 #
# Makefile we are using with a build prefix for shared architecture tools
 #

# Builder will not link objects

BUILDHEADER	:=	AARCH64 shared

BUILDTYPE	:=	$(BUILDTYPE_ARCLIB)

TARGET_SOURCE_DIR	:=	tools

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: all

include $(MKHELPER_DIR)/builder/builder_aarch64.mk

all:	aarch64builder