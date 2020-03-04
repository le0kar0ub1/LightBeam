 #
# Inc make which define static toolchain variable
 #

# GNU ARM NONE EABI toolchain
export NEABI_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/arm-none-eabi-gcc
export NEABI_ARMGNUBASE	:=	$(NEABI_ARMGNUDIR)/bin/arm-none-eabi-
export NEABI_CC			:=	$(NEABI_ARMGNUBASE)gcc
export NEABI_AS			:=	$(NEABI_ARMGNUBASE)as
export NEABI_LD			:=	$(NEABI_ARMGNUBASE)ld
export NEABI_OBJCPY		:=	$(NEABI_ARMGNUBASE)objcopy
export NEABI_OBJDMP		:=	$(NEABI_ARMGNUBASE)objdump
export NEABI_RDELF		:=	$(NEABI_ARMGNUBASE)readelf

# GNU AARCH64 toolchain
export AARCH64_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/aarch64-gnu-tool
export AARCH64_ARMGNUBASE	:=	$(AARCH64_ARMGNUDIR)/bin/arm-none-eabi-
export AARCH64_CC			:=	$(AARCH64_ARMGNUBASE)gcc
export AARCH64_AS			:=	$(AARCH64_ARMGNUBASE)as
export AARCH64_LD			:=	$(AARCH64_ARMGNUBASE)ld
export AARCH64_OBJCPY		:=	$(AARCH64_ARMGNUBASE)objcopy
export AARCH64_OBJDMP		:=	$(AARCH64_ARMGNUBASE)objdump
export AARCH64_RDELF		:=	$(AARCH64_ARMGNUBASE)readelf