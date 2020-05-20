 #
# Makefile at x86 shared object into library
 #

BUILDER_HEADER		:=	x86 shared

BUILDER_TYPE		:=	$(BUILDER_TYPE_STCLIB)

BUILDER_SOURCE_DIR	:=	boot				\
						interrupts			\
						drivers/vga			\
						drivers/serial		\
						init				\
						cpus				\
						system				\
						memory				\

BUILDER_TARGET		:=	$(TGTSHARED_LIBPLT)

.PHONY: all

sinclude $(MKHELPER_DIR)/builder/builder.mk

all:	 lauchbuilder