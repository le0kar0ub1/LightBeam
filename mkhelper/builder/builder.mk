 #
# Template Builder for XXX target
 #

sinclude $(MKHELPER_DIR)/macro.mk
sinclude $(MKHELPER_DIR)/builder/def.mk

TARGET_C_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(BUILDER_SOURCE_DIR)))

TARGET_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(BUILDER_SOURCE_DIR)))

TARGET_C_OBJECT 	=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT	=	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: lauchbuilder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_C_OBJECT) $(TARGET_ASM_OBJECT)

lauchbuilder:	checkup	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)	$(KERNEL)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(GNUBASE)$(CC) $(CCFLAGS) -c $< -o $@
	$(call BUILDER_LOG_COMP,CC)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(GNUBASE)$(AS) $(ASFLAGS) -c $< -o $@
	$(call BUILDER_LOG_COMP,AS)

$(KERNEL):	$(.SECONDEXPANSION)
ifeq ($(BUILDER_TYPE),$(BUILDER_TYPE_BINARY))
	@echo ""
	@$(GNUBASE)$(LD) $(TARGET_BUILT_OBJECT) $(LDFLAGS) -o $(BUILDER_TARGET)
	$(call BUILDER_LOG_LINK,LNK,$@)
	@$(GNUBASE)$(OBJCPY) $(BUILDIR)/$(KERNEL) -O binary $(PROJECT_PATH)/$(IMGKERN)
	$(call BUILDER_LOG_LINK,IMG,$(IMGKERN))
else ifeq ($(BUILDER_TYPE),$(BUILDER_TYPE_STCLIB))
	@$(GNUBASE)$(AR) rcs $(BUILDER_TARGET) $(TARGET_BUILT_OBJECT)
	$(call BUILDER_LOG_LINK,LNK,$(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(BUILDER_TARGET)))
else ifneq ($(BUILDER_TYPE),$(BUILDER_TYPE_NOLINK))
	$(call BUILDERR, invalid build type)
endif


checkup:
ifeq ($(BUILDER_TARGET),)
    ifneq ($(BUILDER_TYPE),$(BUILDER_TYPE_NOLINK))
		$(call BUILDERR, invalid target)
    endif
endif
ifeq ($(BUILDER_HEADER),)
	$(call BUILDERR, invalid header)
else
	$(call BUILDLOG, Building $(BUILDER_HEADER) objects...)
endif

gnucheckup:
ifeq ($(GNUBASE),)
	$(call BUILDERR, invalid compiler)
endif