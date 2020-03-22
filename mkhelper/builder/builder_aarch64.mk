 #
# Template Builder for AARCH64 target
 #

TARGET_C_SOURCE 	+=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_ASM_SOURCE	+=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(TARGET_SOURCE_DIR)))

TARGET_C_OBJECT 	+=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT	+=	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: aarch64builder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_C_OBJECT) $(TARGET_ASM_OBJECT)

aarch64builder:		buildheader	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)	$(KERNEL)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(AARCH64_CC) $(CCFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(AARCH64_AS) $(ASFLAGS) -c $< -o $@
	@-echo -e "     AS      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(KERNEL):	$(.SECONDEXPANSION)
	@echo ""
ifeq ($(BUILDTYPE),$(BUILDTYPE_BINARY))
	@$(AARCH64_LD) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e "    LNK      $@"
	@$(AARCH64_OBJCPY) $(BUILDIR)/$(KERNEL) -O binary $(PROJECT_PATH)/$(IMGKERN)
	@-echo -e "    IMG      $(IMGKERN)"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_PLTLIB))
	@$(AARCH64_AR) rcs $(TGTSHARED_LIBPLT) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LNK      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBPLT))"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_ARCLIB))
	@$(AARCH64_AR) rcs $(TGTSHARED_LIBARC) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LNK      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBARC))"
endif

buildheader:
	@echo -e "\nBuilding $(BUILDHEADER) objects...\n"