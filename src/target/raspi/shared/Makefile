 #
# Makefile at raspi shared object into library
 #

BUILDER_HEADER	:=	raspi shared

BUILDER_TYPE	:=	$(BUILDER_TYPE_STCLIB)

BUILDER_SOURCE_DIR	+=	lib		\

BUILDER_TARGET	:=	$(TGTSHARED_LIBPLT)

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

TARGET_BUILT_OBJECT :=  $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font/font.o

.PHONY: all

all:	 fontbuild lauchbuilder

include $(MKHELPER_DIR)/builder/builder.mk

fontbuild:
	@mkdir -p $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font
	@$(AARCH64_LD) -r -b binary -o $(BUILDIR)/$(TARGET_PREFIX_BUILD)/font/font.o font/font.psf