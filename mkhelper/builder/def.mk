 #
# Inc make which define build variable
 #

# Norm the linker
export TGTLINKER		:=	lightbleam.ld
export TGTLINKER_BUILD	:=	$(KBUILD)

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(KBUILD)

# ARCH directories
export AARCH32_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/aarch32
export AARCH32_SHARED_OBJ_DIR	:=	$(BUILDIR)/$(ARCH_DIR)/aarch32
export AARCH64_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/aarch64
export AARCH64_SHARED_OBJ_DIR	:=	$(BUILDIR)/$(ARCH_DIR)/aarch64
export OVRWLD_SHARED_SRC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(ARCH_DIR)/overworld
export OVRKRN_SHARED_SEC_DIR	:=	$(PROJECT_PATH)/$(ROOT_SRC_DIR)/kernel

# Norm Libraries
export TGTSHARED_LIBPLT	:=	$(BUILDIR)/pltlib.a
export TGTSHARED_LIBARC	:=	$(BUILDIR)/arclib.a
export TGTSHARED_OVRWLD	:=	$(BUILDIR)/ovrwld.a
export TGTSHARED_OVRKRN	:=	$(BUILDIR)/ovrkrn.a

# Norm Assets
export TGTASSETS_DIR	:=	$(BUILDIR)/assets

export BUILDER_TYPE_NOLINK		:=	0
export BUILDER_TYPE_STCLIB		:=	1
export BUILDER_TYPE_BINARY		:=	2

define BUILDERR
	@echo -e "[$(BoldGreen)Builder$(Blank)]$(1)"
	@exit 1
endef

define BUILDLOG
	@echo -e "\n[$(BoldGreen)Builder$(Blank)]$(1)\n"
endef

define BUILDER_LOG_COMP
	@echo -e "     [$(BoldCyan)$(1)$(Blank)]     $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"
endef

define BUILDER_LOG_LINK
	@echo -e "    [$(BoldYellow)$(1)$(Blank)]     $(2)"
endef