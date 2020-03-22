 #
# Makefile we are using with a build prefix for shared architecture tools
 #

# Builder will not link objects
BUILDTYPE	:= $(BUILDTYPE_PLTLIB)

BUILDHEADER	:=	aarch32 shared

TARGET_SOURCE_DIR	:=	tools

.PHONY: all

include $(MKHELPER_DIR)/builder/builder_aarch32.mk

all:	aarch32builder