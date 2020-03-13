 #
# Inc make which define build variable
 #

# Norm the linker
export TGTLINKER		:=	target.ld
export TGTLINKER_BUILD	:=	$(KBUILD)

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(KBUILD)

# Norm Libraries
export TGTSHARED_LIBPLT	:=	$(BUILDIR)/pltlib.a
export TGTSHARED_LIBARC	:=	$(BUILDIR)/arclib.a

# Norm Assets
export TGTASSETS_DIR	:=	$(BUILDIR)/assets

export BUILDTYPE_NOLINK		:=	0
export BUILDTYPE_PLTLIB		:=	1
export BUILDTYPE_SRDLIB		:=	2
export BUILDTYPE_BINARY		:=	3