 #
# Makefile at source root, redirection from target
 #

export ROOT_ARCH_DIR		:=	$(shell realpath arch)
export ROOT_PLATEFORM_DIR	:=	$(shell realpath plateform)

ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

ROOT_SOURCE 	=	$(wildcard *$(EXTENSION_SRC)										\
								$(addsuffix /*$(EXTENSION_SRC), $(ROOT_SOURCE_DIR))		\
								$(addsuffix /**/*$(EXTENSION_SRC), $(ROOT_SOURCE_DIR))	\
					)

ROOT_OBJECT 	= 	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/%$(EXTENSION_OBJ), $(ROOT_SOURCE))


.PHONY: all	subBuild

all:	projectHeader	$(ROOT_OBJECT)	subBuild

projectHeader:
ifeq ($(TARGET),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mNo TARGET architecture given, processus stopped\e[0m\n"
	@exit 1
else ifeq ($(filter $(TARGET),$(ALLOWED_ARCH)),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mThe given TARGET $(TARGET) isn't allowed (must be $(ALLOWED_ARCH))\e[0m\n"
	@exit 1
else
	@echo -e "\n *"
	@echo -e "*  Building $(KERNEL)"
	@echo -e " *\n"
endif

# Savage method
.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

$(KERNEL):	$(.SECONDEXPANSION)
	@$(CC) -o $(KERNEL) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

subBuild:
	@make -C $(ROOT_ARC_DIR)/$(TARGET_BASE) --no-print-directory