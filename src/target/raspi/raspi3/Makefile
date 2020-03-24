 #
# Makefile Compiling object for RASPI3 target
 #

CCFLAGS		+=	-mcpu=cortex-a53

BUILDHEADER	:=	raspi3 target

BUILDTYPE	:=	$(BUILDTYPE_BINARY)

TARGET_SOURCE_DIR	+=	.			\
						boot		\
						tool		\
						driver		\
						interrupt	\
						cpus/init	\
						cpus		\
						memory		\
						system		\

.PHONY: all

all:	arcbuild	aarch64builder

include $(MKHELPER_DIR)/builder/builder_aarch64.mk

arcbuild:
	# @make -C $(OVERWORLD_SHARED_SRC_DIR) --no-print-directory
	@make -C $(AARCH64_SHARED_SRC_DIR) --no-print-directory
