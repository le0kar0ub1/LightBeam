 #
# Makefile Compiling object for RASPI3 target
 #

export GNUBASE	:=	$(AARCH64_ARMGNUBASE)

CCFLAGS		+=	-mcpu=cortex-a53

BUILDER_HEADER	:=	raspi3 target

BUILDER_TYPE	:=	$(BUILDER_TYPE_BINARY)

BUILDER_TARGET	:= tktlecouz

BUILDER_SOURCE_DIR	+=	.			\
						boot		\
						tool		\
						driver		\
						interrupt	\
						cpus/init	\
						cpus		\
						memory		\
						system		\

.PHONY: all

all:	arcbuild	lauchbuilder

include $(MKHELPER_DIR)/builder/builder.mk

arcbuild:
	@make -C $(OVERWORLD_SHARED_SRC_DIR) --no-print-directory
	@make -C ../shared --no-print-directory
	@make -C $(AARCH64_SHARED_SRC_DIR) --no-print-directory
