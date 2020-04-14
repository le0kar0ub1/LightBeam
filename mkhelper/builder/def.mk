 #
# Inc make which define build variable
 #

# Norm the linker
export TGTLINKER		:=	lightbeam.ld
export TGTLINKER_BUILD	:=	$(KBUILD)

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(KBUILD)

# ARCH directories
export ARCH_BASE_SRC_DIR		:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/
export OVRKRN_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/kernel

# Norm Libraries
export TGTSHARED_LIBPLT	=	$(BUILDIR)/static/$(TGTARCH)-pltlib.a
export TGTSHARED_LIBARC	=	$(BUILDIR)/static/$(TGTARCH)-arclib.a
export TGTSHARED_OVRKRN	=	$(BUILDIR)/static/$(TGTARCH)-ovrkrn.a

# Norm Assets
export TGTASSETS_DIR	:=	$(BUILDIR)/assets

export BUILDER_TYPE_NOLINK		:=	BUILDER_TYPE_NOLINK
export BUILDER_TYPE_STCLIB		:=	BUILDER_TYPE_STCLIB
export BUILDER_TYPE_RAWKRN		:=	BUILDER_TYPE_RAWKRN
export BUILDER_TYPE_x86GRUB		:=	BUILDER_TYPE_x86GRUB

export BUILD_KRN_OBJDIR := $(BUILDIR)/kernel
export BUILD_ARC_OBJDIR := $(BUILDIR)/arch
export BUILD_TGT_OBJDIR := $(BUILDIR)/target/$(TARGET)
export BUILD_PLT_OBJDIR := $(BUILDIR)/target/$(TARGET)/$(TARGET2SHARED_DIR)

define BUILDERR
	@echo -e "[$(BoldGreen)BUILDER$(Blank)]$(1)"
	@exit 1
endef

define BUILDLOG
	@echo -e "\n[$(BoldGreen)BUILDER$(Blank)]$(1)\n"
endef

define BUILDER_LOG_COMP
	@echo -e "     [$(BoldCyan)$(1)$(Blank)]     $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"
endef

define BUILDER_LOG_LINK
	@echo -e "    [$(BoldYellow)$(1)$(Blank)]     $(2)"
endef