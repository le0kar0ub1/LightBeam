 #
# Makefile Compiling object for RASPI3 target
 #

CCFLAGS		+=	-mcpu=cortex-a53

BUILDHEADER	:=	raspberry3 target

TARGET_SOURCE_DIR	+=	.			\
						boot		\
						tool		\
						driver		\
						interrupt	\
						cpus		\

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

# Shared ARCH object
.EXPANSION:
TARGET_BUILT_OBJECT		=	$(shell find $(AARCH64_SHARED_OBJ_DIR) -name *$(EXTENSION_OBJ) 2> /dev/null)
TARGET_BUILT_OBJECT		+=	$(TARGET_PREBUILD)

.PHONY: all

all:	sharedbuild	$(.EXPANSION)	aarch64builder

include $(MKHELPER_DIR)/builder/builder_aarch64.mk

sharedbuild:
	@make -C $(AARCH64_SHARED_SRC_DIR) --no-print-directory
