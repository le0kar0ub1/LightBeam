 #
# Template Builder for AARCH64 target
 #

TARGET_C_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(TARGET_SOURCE_DIR)))

TARGET_C_OBJECT 	= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT 	= 	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

.PHONY: aarch64builder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	=	$(TARGET_C_OBJECT) $(TARGET_ASM_OBJECT)

aarch64builder:	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)	$(KERNEL)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(AARCH64_CC) $(CCFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell basename $(BUILDIR))/$(TARGET_PREFIX_BUILD)/$(shell basename $@)"

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(AARCH64_AS) $(ASFLAGS) -c $< -o $@
	@-echo -e "     AS      $(shell basename $(BUILDIR))/$(TARGET_PREFIX_BUILD)/$(shell basename $@)"

$(KERNEL):	$(.SECONDEXPANSION)
	@$(AARCH64_CC) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"