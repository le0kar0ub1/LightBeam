 #
# Makefile Compiling object for RASPI2 target
 #

TARGET_SOURCE_DIR	:=	boot	\
						core

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

TARGET_C_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(TARGET_SOURCE_DIR)))

TARGET_C_OBJECT 	= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT 	= 	$(patsubst %$(EXTENSION_ASM), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

.PHONY: all

all:	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell basename $(BUILDIR))/$(TARGET_PREFIX_BUILD)/$(shell basename $@)"

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASFLAGS) -c $< -o $@
	@-echo -e "     AS      $(shell basename $(BUILDIR))/$(TARGET_PREFIX_BUILD)/$(shell basename $@)"