 #
# Root Makefile project, calling sub-build
 #

include mk/def.mk
include mk/macro.mk

# Savage method
.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

.PHONY: all build fclean debug clean $(KERNEL)

all:	prebuild	build	$(KERNEL)

prebuild:
	$(call EvalToolchain)

build:
	exit 1

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

toolchain:
	./mktoolchain/mktoolchain

run:	$(KERNEL)
ifeq ($(EXEC),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mYou must specify a kernel to exec\e[0m\n"
	@exit 1
else
	@$(QEMU) $(QEMUFLAGS) -M ast2500-evb -cpu arm1176 -kernel $(EXEC)
endif