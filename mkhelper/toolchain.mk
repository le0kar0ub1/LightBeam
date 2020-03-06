 #
# Inc make which define static toolchain variable
 #

# GNU AARCH32 toolchain
export AARCH32_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/aarch32-gnu-tool
export AARCH32_ARMGNUBASE	:=	$(AARCH32_ARMGNUDIR)/bin/arm-none-eabi-
export AARCH32_CC			:=	$(AARCH32_ARMGNUBASE)gcc
export AARCH32_AS			:=	$(AARCH32_ARMGNUBASE)as
export AARCH32_LD			:=	$(AARCH32_ARMGNUBASE)ld
export AARCH32_OBJCPY		:=	$(AARCH32_ARMGNUBASE)objcopy
export AARCH32_OBJDMP		:=	$(AARCH32_ARMGNUBASE)objdump
export AARCH32_RDELF		:=	$(AARCH32_ARMGNUBASE)readelf

export AARCH32_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/aarch32
export AARCH32_SHARED_OBJ_DIR	:=	$(BUILDIR)/$(ARCH_DIR)/aarch32

# GNU AARCH64 toolchain
export AARCH64_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/aarch64-gnu-tool
export AARCH64_ARMGNUBASE	:=	$(AARCH64_ARMGNUDIR)/bin/aarch64-linux-gnu-
export AARCH64_CC			:=	$(AARCH64_ARMGNUBASE)gcc
export AARCH64_AS			:=	$(AARCH64_ARMGNUBASE)as
export AARCH64_LD			:=	$(AARCH64_ARMGNUBASE)ld
export AARCH64_OBJCPY		:=	$(AARCH64_ARMGNUBASE)objcopy
export AARCH64_OBJDMP		:=	$(AARCH64_ARMGNUBASE)objdump
export AARCH64_RDELF		:=	$(AARCH64_ARMGNUBASE)readelf

export AARCH64_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/aarch64
export AARCH64_SHARED_OBJ_DIR	:=	$(BUILDIR)/$(ARCH_DIR)/aarch64