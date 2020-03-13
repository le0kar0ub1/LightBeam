 #
# Makefile at raspi shared object into library
 #

BUILDHEADER	:=	raspi shared library

BUILDTYPE	:=	$(BUILDTYPE_PLTLIB)

TARGET_SOURCE_DIR	+=	lib		\

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

TARGET_BUILT_OBJECT :=  $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font/font.o

.PHONY: all

all:	 fontbuild aarch64builder

include $(MKHELPER_DIR)/builder/builder_aarch64.mk

fontbuild:
	@mkdir -p $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font
	@$(AARCH64_LD) -r -b binary -o $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font/font.o font/font.psf