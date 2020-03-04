 #
# Inc make which define static variable
 #

export BUILDIR	:=	$(realpath .)/build

export MKHELPER_DIR	:=	$(shell realpath .)/mk

export PROJECT_PATH	:=	$(shell realpath .)

export ROOT_SRC_DIR	:=	src
export ROOT_INC_DIR	:=	inc

export TARGET_DIR	:=	target
export ARCH_DIR		:=	arch

export INCLUDE_DIR =	$(addprefix -I$(realpath $(ROOT_INC_DIR))/,		.)

INCLUDE_DIR	+= $(addprefix -I$(realpath $(ROOT_INC_DIR)/$(ROOT_ARC_DIR))/,						\
						/																		\
				)

export ARMGNUDIR	:=	mktoolchain/toolchain/arm-none-eabi-gcc
export ARMGNUBASE	:=	$(ARMGNUDIR)/bin/arm-none-eabi-
export CC			:=	$(ARMGNUBASE)gcc
export AS			:=	$(ARMGNUBASE)as
export LD			:=	$(ARMGNUBASE)ld
export OBJCPY		:=	$(ARMGNUBASE)objcopy
export OBJDMP		:=	$(ARMGNUBASE)objdump
export READELF		:=	$(ARMGNUBASE)readelf

export REALPATH_PROJECT	:=	$(realpath .)
export PROJECT			:=	LightBleam
export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export KERNEL			:=	$(PROJECT)-$(VERSION)-$(TARGET).$(BIN_EXTENSION)

export EXTENSION_SRC	:=	.c
export EXTENSION_OBJ	:=	.o
export EXTENSION_ASM	:=	.S

export LDFLAGS	=	--trace

export RM	=	rm -rf

# Cleaner as possible
export CFLAGS	=	$(INCLUDE_DIR)						\
					-MMD								\
					-MF		dep.d						\
					-Wall								\
					-Wextra				 				\
					-Wnested-externs					\
					-Winline							\
					-Wpragmas							\
					--std=gnu11							\
					-Wuninitialized						\
					-Wno-missing-braces					\
					-Wcast-align						\
					-Wwrite-strings						\
					-static					 			\
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
					-lm									\
					-mno-red-zone						\
					-Werror

export QEMU			:=	qemu-system-arm

export QEMUFLAGS	:=	-no-reboot 		\
						-serial stdio


# Compile-time Macro
CFLAGS		+=	'-D PROJECT_NAME="$(PROJECT)"'			\
				'-D TARGETED_ARCH="$(TARGET)"'

# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += $(CFLAGSDEBUG)
endif


# Hide It
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