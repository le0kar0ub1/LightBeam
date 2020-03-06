 #
# Makefile Compiling object for RASPI0/1 target
 #


TARGET_SOURCE_DIR	+=	boot	\
						core

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

# Shared ARCH object
.EXPANSION:
TARGET_BUILT_OBJECT		=	$(shell find $(AARCH32_SHARED_OBJ_DIR) -name *$(EXTENSION_OBJ) 2> /dev/null)

.PHONY: all

all:	sharedbuild	$(.EXPANSION)	aarch32builder

include $(MKHELPER_DIR)/builder/builder_aarch32.mk

sharedbuild:
	@make -C $(AARCH32_SHARED_SRC_DIR) --no-print-directory
