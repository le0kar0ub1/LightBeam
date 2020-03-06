 #
# Makefile Compiling object for RASPI0 target
 #


TARGET_SOURCE_DIR	+=	boot	\
						core

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: all

include $(MKHELPER_DIR)/builder/builder_aarch32.mk

all:	aarch32builder
