 #
# Makefile Compiling object for i386 target
 #

sinclude $(MKHELPER_DIR)/builder/def.mk

export TGTARCH	:=	i386

export GNUBASE	:=

GRUBCFG		:=	grub.cfg

# Particular CC flags
CCFLAGS		+=	-march=i386	\
				-m32

ASFLAGS		+=	--32				\
				--defsym sysz=32	\

LDFLAGS		+=	-m elf_i386

# The library we use
LDFLAGS		+=	#$(TGTSHARED_LIBPLT)					\
				#$(TGTSHARED_LIBARC)					\
				$(TGTSHARED_OVRKRN)						\

BUILDER_HEADER	:=	$(TGTARCH) target

BUILDER_TYPE	:=	$(BUILDER_TYPE_ISOKRN)

BUILDER_TARGET	:=	$(BUILDIR)/$(KERNEL)

BUILDER_SOURCE_DIR	=	boot			\
						descriptors		\
						kernel			\
						interrupts		\

.PHONY: all

all:	toolchainCheckup	arcbuild	lauchbuilder

sinclude $(MKHELPER_DIR)/builder/builder.mk

arcbuild:
	# @make -s -C $(ARCH_BASE_SRC_DIR)/$(TGTARCH) --no-print-directory
	# @make -s -C $(OVRKRN_SHARED_SRC_DIR) --no-print-directory
	# @make -s -C $(TARGET2SHARED_DIR) --no-print-directory

toolchainCheckup:
	$(call EvalBinaryExistence,as)
	$(call EvalBinaryExistence,gcc)
	$(call EvalBinaryExistence,ld)
	$(call EvalBinaryExistence,grub-mkrescue)