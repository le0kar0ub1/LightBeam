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

# We Will provide the full path each time
export INCLUDE_DIR =	-I $(realpath $(ROOT_INC_DIR))

# Norm the linker
export TGTLINKER		:=	target.ld
export TGTLINKER_BUILD	:=	$(KBUILD)

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(KBUILD)

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

export LDFLAGS	=	--trace								\
					-ffreestanding 						\
					-nostdlib							\
					-nostartfiles						\
					-o	$(PROJECT_PATH)/$(KERNEL)		\
					-T	$(TGTLINKER_BUILD)/$(TGTLINKER)	\
					-lgcc								\

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
					-std=gnu99							\
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
					# -O2 								\
					# -static					 		\
					# -fpic								\
					# -Werror

export ASFLAGS	=	$(INCLUDE_DIR)						\

export QEMU			:=	qemu-system-arm

export QEMUFLAGS	:=	-no-reboot 		\
						-serial stdio


# Compile-time Macro
CFLAGS		+=	'-D PROJECT="$(PROJECT)"'			\
				'-D TARGET="$(TARGET)"'

# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
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