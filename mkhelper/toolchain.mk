 #
# Inc make which define static toolchain variable
 #

export CC		:=	gcc
export AS		:=	as
export AR		:=	ar
export LD		:=	ld
export OBJCPY	:=	objcopy
export OBJDMP	:=	objdump
export RDELF	:=	readelf

# GNU AARCH32 toolchain
export AARCH32_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/aarch32-gnu-tool
export AARCH32_ARMGNUBASE	:=	$(AARCH32_ARMGNUDIR)/bin/arm-none-eabi-
export AARCH32_CC			:=	$(AARCH32_ARMGNUBASE)$(CC)
export AARCH32_AS			:=	$(AARCH32_ARMGNUBASE)$(AS)
export AARCH32_AR			:=	$(AARCH32_ARMGNUBASE)$(AR)
export AARCH32_LD			:=	$(AARCH32_ARMGNUBASE)$(LD)
export AARCH32_OBJCPY		:=	$(AARCH32_ARMGNUBASE)$(OBJCPY)
export AARCH32_OBJDMP		:=	$(AARCH32_ARMGNUBASE)$(OBJDMP)
export AARCH32_RDELF		:=	$(AARCH32_ARMGNUBASE)$(RDELF)

# GNU AARCH64 toolchain
export AARCH64_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/aarch64-gnu-tool
export AARCH64_ARMGNUBASE	:=	$(AARCH64_ARMGNUDIR)/bin/aarch64-linux-gnu-
export AARCH64_CC			:=	$(AARCH64_ARMGNUBASE)$(CC)
export AARCH64_AS			:=	$(AARCH64_ARMGNUBASE)$(AS)
export AARCH64_AR			:=	$(AARCH64_ARMGNUBASE)$(AR)
export AARCH64_LD			:=	$(AARCH64_ARMGNUBASE)$(LD)
export AARCH64_OBJCPY		:=	$(AARCH64_ARMGNUBASE)$(OBJCPY)
export AARCH64_OBJDMP		:=	$(AARCH64_ARMGNUBASE)$(OBJDMP)
export AARCH64_RDELF		:=	$(AARCH64_ARMGNUBASE)$(RDELF)