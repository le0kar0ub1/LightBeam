 #
# Template Builder for AARCH64 target
 #

include $(MKHELPER_DIR)/macro.mk

TARGET_C_SOURCE 	+=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(BUILDER_SOURCE_DIR)))

TARGET_ASM_SOURCE	+=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(BUILDER_SOURCE_DIR)))

TARGET_C_OBJECT 	+=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT	+=	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: lauchbuilder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_C_OBJECT) $(TARGET_ASM_OBJECT)

lauchbuilder:	checkup	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)	$(KERNEL)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(GNUBASE)$(CC) $(CCFLAGS) -c $< -o $@
	@-echo -e "     $(BoldCyan)CC$(Blank)      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(GNUBASE)$(AS) $(ASFLAGS) -c $< -o $@
	@-echo -e "     $(BoldCyan)AS$(Blank)      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(KERNEL):	$(.SECONDEXPANSION)
ifeq ($(BUILDER_TYPE),$(BUILDER_TYPE_BINARY))
	@echo ""
	@$(GNUBASE)$(LD) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e "    $(BoldYellow)LNK$(Blank)      $@"
	@$(GNUBASE)$(OBJCPY) $(BUILDIR)/$(KERNEL) -O binary $(PROJECT_PATH)/$(IMGKERN)
	@-echo -e "    $(BoldYellow)IMG$(Blank)      $(IMGKERN)"
else ifeq ($(BUILDER_TYPE),$(BUILDER_TYPE_STCLIB))
	@$(GNUBASE)$(AR) rcs $(BUILDER_TARGET) $(TARGET_BUILT_OBJECT)
	@-echo -e "    $(BoldYellow)LNK$(Blank)      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(BUILDER_TARGET))"
else ifneq ($(BUILDER_TYPE),$(BUILDER_TYPE_NOLINK))
	$(call BUILDERR, invalid build type)
endif

checkup:
ifeq ($(GNUBASE),)
	$(call BUILDERR, invalid compiler)
endif
ifeq ($(BUILDER_TARGET),)
	$(call BUILDERR, invalid target)
endif
ifeq ($(BUILDER_HEADER),)
	$(call BUILDERR, invalid header)
else
	$(call BUILDLOG, Building $(BUILDER_HEADER) objects...)
endif