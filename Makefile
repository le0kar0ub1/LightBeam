 #
# Root Makefile project, calling sub-build
 #

include mk/def.mk
include mk/rules.mk

export BUILDIR	:=	$(realpath .)/build

export ROOT_SRC_DIR	:= src
export ROOT_INC_DIR	:= inc
export ROOT_ARC_DIR	:= arch

export INCLUDE_DIR =	$(addprefix -I$(realpath $(ROOT_INC_DIR))/,		.)

INCLUDE_DIR	+= $(addprefix -I$(realpath $(ROOT_INC_DIR)/$(ROOT_ARC_DIR))/,						\
						/																		\
						$(TARGET)																\
				)

# Savage method
.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

.PHONY: all build fclean debug clean $(KERNEL)

all:	build	$(KERNEL)

build:

disassemble: $(KERNEL)
	@objdump --no-show-raw-insn -d -Mintel $(KERNEL) | source-highlight -s asm -f esc256 | less -eRiMX

re:	fclean all

clean:
	@$(RM) $(BUILDIR)

fclean:	clean
	@$(RM) $(PROJECT)*.bin 
	@$(RM) vgcore.*
	@$(RM) $(shell $(realpath $(find . -name dep.d)))

$(KERNEL):	$(.SECONDEXPANSION)
	@$(CC) -o $(KERNEL) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

run:	$(KERNEL)
# Savage method
	@$(QEMU) $(QEMUFLAGS) -M ast2500-evb -cpu arm1176 -kernel $(PROJECT)_$(ARCH_HOST)-$(VERSION)*