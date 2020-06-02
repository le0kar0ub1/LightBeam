 #
# Inc make which define static variable
 #

# Built for link
export BUILDIR		:=	$(realpath .)/build
export KBUILD		:=	$(BUILDIR)/kbuild
export STATICBUILD	:=	$(BUILDIR)/static
export BUILDNEED	:=	$(KBUILD)		\
						$(STATICBUILD)

export MKHELPER_DIR	:=	$(shell realpath .)/mkhelper

export PROJECT_PATH	:=	$(shell realpath .)

export TARGET_BASE	:=	$(shell basename $(TARGET)/)
export TARGET_ROOT	:=	$(shell echo $(TARGET) | cut -d / -f 1)

# Root diretcories
export ROOT_SRC_DIR	:=	src
export ROOT_INC_DIR	:=	inc

# Sub Source Directories
export TARGET_DIR	:=	target
export ARCH_DIR		:=	arch

# Shared calculation
export TARGET2SHARED_DIR	:=	../common

# We Will provide the full path each time
export INCLUDE_DIR =	$(realpath $(ROOT_INC_DIR))

# Binary definition
export PROJECT			:=	LightBeam
# export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export IMG_EXTENSION	:=	img
export ISO_EXTENSION	:=	iso
export KERNEL			:=	$(PROJECT)-$(TARGET_BASE).$(BIN_EXTENSION)
export IMGKERN			:=	$(PROJECT)-$(TARGET_BASE).$(IMG_EXTENSION)
export ISOKERN			:=	$(PROJECT)-$(TARGET_BASE).$(ISO_EXTENSION)

# Norm extension
export EXTENSION_SRC	:=	.c
export EXTENSION_OBJ	:=	.o
export EXTENSION_ASM	:=	.S
export EXTENSION_LIB	:=	.a

export LDFLAGS			=	-T	$(TGTLINKER_BUILD)/$(TGTLINKER)		\
							-nostdlib								\
							-z max-page-size=0x1000					\
							-g										\
							-L	$(STATICBUILD)/*$(EXTENSION_LIB)	\

export LDFLAGS_DEBUG	=	--trace					\
							--cref					\
							--print-map				\

export RM	:=	rm -rf

export BUILDEP	:=	dep.dep

# Cleaner as possible
export CCFLAGS	=	-I $(INCLUDE_DIR)					\
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
					-fno-stack-protector				\
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
					-Wno-override-init					\
					-Wno-unused-function				\
					-static					 			\
					# -Werror							\
					-MD									\
					-MP									\
					-MF		dep.dep						\

export ASFLAGS	=	-I	$(INCLUDE_DIR)						\

# Compile-time Macro
CFLAGS		+=	'-D PROJECT="$(PROJECT)"'			\
				'-D TARGET="$(TARGET)"'				\
				'-D TARGET_BASE="$(TARGET_BASE)"'	\
				--D TARGET_ROOT="$(TARGET_ROOT)"'	\

# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS		+= $(CFLAGSDEBUG)
    LDFLAGS		+= $(LDFLAGS_DEBUG)
endif

# Output coloration
export Red			:= \e[0;31m
export BoldRed		:= \e[1;31m
export Green		:= \e[0;32m
export BoldGreen	:= \e[1;32m
export Yellow		:= \e[0;33m
export BoldYellow	:= \e[1;33m
export Blue			:= \e[0;34m
export BoldBlue		:= \e[1;34m
export Magenta		:= \e[0;35m
export BoldMagenta 	:= \e[1;35m
export Cyan			:= \e[0;36m
export BoldCyan		:= \e[1;36m
export Blank		:= \e[0m