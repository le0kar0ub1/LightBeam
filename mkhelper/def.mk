 #
# Inc make which define static variable
 #

# Built for link
export BUILDIR	:=	$(realpath .)/build
export KBUILD	:=	$(BUILDIR)/kbuild

export MKHELPER_DIR	:=	$(shell realpath .)/mkhelper

export PROJECT_PATH	:=	$(shell realpath .)

# Root diretcories
export ROOT_SRC_DIR	:=	src
export ROOT_INC_DIR	:=	inc

# Sub Source Directories
export TARGET_DIR	:=	target
export ARCH_DIR		:=	arch

# Shared calculation
export TARGET2SHARED_DIR	:=	../shared

# We Will provide the full path each time
export INCLUDE_DIR =	-I $(realpath $(ROOT_INC_DIR))

# Binary definition
export PROJECT			:=	LightBleam
# export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export IMG_EXTENSION	:=	img
export KERNEL			:=	$(PROJECT)-$(TARGET).$(BIN_EXTENSION)
export IMGKERN			:=	$(PROJECT)-$(TARGET).$(IMG_EXTENSION)

# Norm extension
export EXTENSION_SRC	:=	.c
export EXTENSION_OBJ	:=	.o
export EXTENSION_ASM	:=	.S
export EXTENSION_LIB	:=	.a

export LDFLAGS			=	-nostdlib							\
							-nostartfiles						\
							-n									\
							-T	$(TGTLINKER_BUILD)/$(TGTLINKER)	\
							-L	$(BUILDIR)						\
							$(TGTSHARED_LIBARC)					\
							$(TGTSHARED_LIBPLT)					\
							$(TGTSHARED_OVRLIB)					\

export LDFLAGS_DEBUG	=	--trace					\
							--cref					\
							--print-map				\

export RM	:=	rm -rf

export BUILDEP	:=	dep.d

# Cleaner as possible
export CCFLAGS	=	$(INCLUDE_DIR)						\
					-MMD								\
					-MF		$(BUILDEP)					\
					-Wall								\
					-Wextra				 				\
					-Wnested-externs					\
					-Winline							\
					-Wpragmas							\
					-ffreestanding 						\
					-std=gnu11							\
					-Wuninitialized						\
					-Wno-missing-braces					\
					-Wcast-align						\
					-Wwrite-strings						\
					-Wparentheses						\
					-Wunreachable-code					\
					-Wunused							\
					-Wmissing-field-initializers		\
					-Wswitch-enum						\
					-Wshadow				 			\
					-Wuninitialized				 		\
					-Wmissing-declarations				\
					-Wmissing-prototypes				\
					-Wstrict-prototypes					\
					-Wpointer-arith						\
					-nostartfiles						\
					-nostdlib							\
					-O2 								\
					-fno-tree-loop-vectorize 			\
					-fno-tree-slp-vectorize				\
					# -Werror

export ASFLAGS	=	$(INCLUDE_DIR)						\

export QEMU-AARCH64		:=	qemu-system-aarch64
export QEMU-ARM			:=	qemu-system-arm

export QEMUFLAGS	=	-serial stdio	\
						-show-cursor

export QEMUDEBUG	=	-d in_asm,int,cpu


# Compile-time Macro
CFLAGS		+=	'-D PROJECT="$(PROJECT)"'			\
				'-D TARGET="$(TARGET)"'

# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS 	+= $(CFLAGSDEBUG)
	LDFLAGS	+= $(LDFLAGS_DEBUG)
endif

# Output coloration
export Red			:= \e[0;31m
export BoldRed		:= \e[1;31m
export Green		:= \e[0;32m
export BoldGreen	:= \e[1;32m
export Yellow		:= \e[0;33m
export BoldYellow	:= \e[01;33m
export Blue			:= \e[0;34m
export BoldBlue		:= \e[1;34m
export Magenta		:= \e[0;35m
export BoldMagenta 	:= \e[1;35m
export Cyan			:= \e[0;36m
export BoldCyan		:= \e[1;36m
export Blank		:= \e[0m