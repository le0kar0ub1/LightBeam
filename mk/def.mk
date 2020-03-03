 #
# Inc make which define static variable
 #

export ARMGNU	:=	arm-none-eabi-
export CC		:=	$(ARMGNU)gcc
export AS		:=	$(ARMGNU)as

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