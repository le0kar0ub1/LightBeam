 #
# Makefile Compiling object for x86_64 target
 #

sinclude $(MKHELPER_DIR)/builder/def.mk

export TGTARCH	:=	x86_64

export GNUBASE	:=

GRUBCFG		:=	grub.cfg

# Particular CC flags
CCFLAGS		+=	-march=x86-64			\
				-mno-red-zone			\
				-fms-extensions 		\
				-fno-stack-protector 	\
				-fno-builtin			\
				-Wcast-align			\
	  	  		-mcmodel=large 			\
		  		#-msse4.1				\

ASFLAGS		+=	--defsym sysz=64

LDFLAGS		+=	-m elf_x86_64

# The library we are using
LDFLAGS			+=	$(TGTSHARED_OVRKRN)

BUILDER_HEADER	:=	$(TGTARCH) target

BUILDER_TYPE	:=	$(BUILDER_TYPE_x86GRUB)

BUILDER_TARGET	:=	$(BUILDIR)/$(KERNEL)

BUILDER_SOURCE_DIR	=	boot			\
						descriptors		\
						kernel			\
						interrupts		\
						cpus			\
						memory			\

.PHONY: all

all:	toolchainCheckup	arcbuild	lauchbuilder

sinclude $(MKHELPER_DIR)/builder/builder.mk

arcbuild:
	@make -s -C $(OVRKRN_SHARED_SRC_DIR) --no-print-directory
	@make -s -C $(TARGET2SHARED_DIR) --no-print-directory

toolchainCheckup:
	$(call EvalBinaryExistence,as)
	$(call EvalBinaryExistence,gcc)
	$(call EvalBinaryExistence,ld)
	$(call EvalBinaryExistence,grub-mkrescue)
	$(call EvalBinaryExistence,xorriso)

ifeq ($(DEBUG),1)
    QEMUOPT = -monitor stdio --no-reboot
else
    QEMUOPT = -serial stdio 
endif
run:
	@qemu-system-x86_64 -cdrom $(BUILDIR)/$(ISOKERN) 	\
						-enable-kvm						\
						$(QEMUOPT)						\
						-m 4G							\