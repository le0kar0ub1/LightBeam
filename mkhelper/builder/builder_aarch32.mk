 #
# Template Builder for AARCH32 target
 #

TARGET_C_SOURCE 	+=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_ASM_SOURCE	+=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(TARGET_SOURCE_DIR)))

TARGET_C_OBJECT 	+=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT	+=	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

.PHONY: aarch32builder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_C_OBJECT) $(TARGET_ASM_OBJECT)

aarch32builder:		buildheader	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)	$(KERNEL)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(AARCH32_CC) $(CCFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(AARCH32_AS) $(ASFLAGS) -c $< -o $@
	@-echo -e "     AS      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(KERNEL):	$(.SECONDEXPANSION)
	@echo ""
ifeq ($(BUILDTYPE),$(BUILDTYPE_BINARY))
	@$(AARCH32_LD) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e "    LNK      $@"
	@$(AARCH32_OBJCPY) $(BUILDIR)/$(KERNEL) -O binary $(PROJECT_PATH)/$(IMGKERN)
	@-echo -e "    IMG      $(IMGKERN)"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_PLTLIB))
	@$(AARCH32_AR) rcs $(TGTSHARED_LIBPLT) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LIB      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBPLT))"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_ARCLIB))
	@$(AARCH32_AR) rcs $(TGTSHARED_LIBARC) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LIB      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBARC))"
endif

buildheader:
	@echo -e "\nBuilding $(BUILDHEADER) objects...\n"