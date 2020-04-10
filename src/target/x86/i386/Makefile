 #
# Makefile Compiling object for I386 target
 #

sinclude $(MKHELPER_DIR)/builder/def.mk

export TGTARCH	:=	i386

export GNUBASE	:=

GRUBCFG		:=	grub.cfg

# Particular CC flags
CCFLAGS		+=	-march=i386	\
				-m32

ASFLAGS		+=	--32

LDFLAGS		+=	-m elf_i386

# The library we use
# LDFLAGS		+=	$(TGTSHARED_LIBARC)					\
				$(TGTSHARED_LIBPLT)					\
				$(TGTSHARED_OVRKRN)					\

BUILDER_HEADER	:=	$(TGTARCH) target

BUILDER_TYPE	:=	$(BUILDER_TYPE_ELFBIN)

BUILDER_TARGET	:=	$(BUILDIR)/$(KERNEL)

BUILDER_SOURCE_DIR	+=	boot

.PHONY: all

all:	lauchbuilder	isobuild

sinclude $(MKHELPER_DIR)/builder/builder.mk

arcbuild:
	# @make -s -C $(ARCH_BASE_SRC_DIR)/$(TGTARCH) --no-print-directory
	# @make -s -C $(OVRKRN_SHARED_SRC_DIR) --no-print-directory
	# @make -s -C $(TARGET2SHARED_DIR) --no-print-directory

isobuild:
	@mkdir -p $(KBUILD)/isofiles/boot/grub
	@cp $(KERNEL) $(KBUILD)/isofiles/boot/kernel.bin
	@cp $(GRUBCFG) $(KBUILD)/isofiles/boot/grub
	@grub-mkrescue -o $(iso) $(KBUILD)/isofiles 2> /dev/null
	@rm -r $(KBUILD)/isofiles
	@$(call BUILDER_LOG_LINK,ISO,$(ISOKERNEL))