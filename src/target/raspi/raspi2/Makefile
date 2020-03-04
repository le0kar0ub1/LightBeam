 #
# Makefile Compiling object for RISCV32 target
 #

TARGET_SOURCE_DIR	:=	boot	\
						core

TGTBUILD	:=	build

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

TARGET_C_SOURCE 	:=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_ASM_SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION_ASM), $(TARGET_SOURCE_DIR)))

TARGET_C_OBJECT 	= 	$(patsubst %$(EXTENSION_SRC), $(TGTBUILD)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_C_SOURCE))

TARGET_ASM_OBJECT 	= 	$(patsubst %$(EXTENSION_ASM), $(TGTBUILD)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_ASM_SOURCE))

.PHONY: all

all:	$(TARGET_C_OBJECT)	$(TARGET_ASM_OBJECT)

$(TGTBUILD)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(PROJECT_PATH) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"

$(TGTBUILD)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_ASM)
	@mkdir -p $(shell dirname $@)
	@exit
	@$(CC) -c $< -o $@
	@-echo -e "     AS      $(shell echo $@ | cut -f $(shell echo "$(shell echo $(PROJECT_PATH) | tr -cd '/' | wc -c)" + 2 | bc)- -d /)"