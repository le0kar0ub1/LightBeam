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

# GNU ARM NONE EABI toolchain
export ARMNEABI_ARMGNUDIR	:=	$(PROJECT_PATH)/mktoolchain/toolchain/arm-none-eabi-gnu
export ARMNEABI_ARMGNUBASE	:=	$(ARMNEABI_ARMGNUDIR)/bin/arm-none-eabi-
export ARMNEABI_CC			:=	$(ARMNEABI_ARMGNUBASE)$(CC)
export ARMNEABI_AS			:=	$(ARMNEABI_ARMGNUBASE)$(AS)
export ARMNEABI_AR			:=	$(ARMNEABI_ARMGNUBASE)$(AR)
export ARMNEABI_LD			:=	$(ARMNEABI_ARMGNUBASE)$(LD)
export ARMNEABI_OBJCPY		:=	$(ARMNEABI_ARMGNUBASE)$(OBJCPY)
export ARMNEABI_OBJDMP		:=	$(ARMNEABI_ARMGNUBASE)$(OBJDMP)
export ARMNEABI_RDELF		:=	$(ARMNEABI_ARMGNUBASE)$(RDELF)

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