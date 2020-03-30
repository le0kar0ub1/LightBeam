 #
# Makefile Compiling object for RASPI3 target
 #

export TGTARCH	:=	aarch64

export GNUBASE	:=	$(AARCH64_ARMGNUBASE)

CCFLAGS		+=	-march=armv8-a 		\
				-mcpu=cortex-a53 	\
				-mtune=cortex-a53 	\
				#-mstrict-align

CCFLAGS		+=	-D__ARM64_ARCH__ 	\
				-D__CORTEX_A53__ 	\
				-D__ARM64_NEON__

BUILDER_HEADER	:=	raspi3 target

BUILDER_TYPE	:=	$(BUILDER_TYPE_BINARY)

BUILDER_TARGET	:= $(BUILDIR)/$(KERNEL)

BUILDER_SOURCE_DIR	+=	.				\
						boot			\
						cpus			\
						cpus/init		\
						interrupts		\
						bcm2837/gpio	\
						bcm2837/mbox	\
						bcm2837/uart	\
						#tools		\
						drivers		\
						memory		\
						system		\

.PHONY: all

all:	arcbuild	lauchbuilder

sinclude $(MKHELPER_DIR)/builder/builder.mk

arcbuild:
	@make -s -C $(OVRWLD_SHARED_SRC_DIR) --no-print-directory
	@make -s -C $(AARCH64_SHARED_SRC_DIR) --no-print-directory
	@make -s -C $(OVRKRN_SHARED_SEC_DIR) --no-print-directory
	@make -s -C $(TARGET2SHARED_DIR) --no-print-directory
