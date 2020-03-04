 #
# Root Makefile project, calling sub-build
 #

include mkhelper/def.mk
include mkhelper/macro.mk

## COMPILTE-TIME ARGS ##
export PLATEFORM := $(TARGET)

.PHONY: all prebuld build fclean debug clean $(KERNEL)

all:	prebuild	build	$(KERNEL)

# Evaluate if the build is correct
prebuild:
	$(call EvalToolchain)
	$(call EvalTargetBuild)

checkup:
	# $(call EvalTargetMachine, $(PLATEFORM))
	# $(call EvalTargetProcessor, $(PROCESSOR))
	# $(call EvalTargetArch, $(ARCH))

# Lauch the build
build:
	@make -C $(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(PLATEFORM_DIR)/$(PLATEFORM) --no-print-directory

# Disassemble the kernel (debug)
disassemble: $(KERNEL)
	@objdump --no-show-raw-insn -d -Mintel $(KERNEL) | source-highlight -s asm -f esc256 | less -eRiMX

re:	fclean all

# Clean the relocatable objects
clean:
	@$(RM) $(BUILDIR)

# Full clean the projet
fclean:	clean
	@$(RM) $(PROJECT)*.bin 
	@$(RM) vgcore.*
	@$(RM) $(shell $(realpath $(find . -name dep.d)))

# Build & check toolchain
toolchain:
	./mktoolchain/mktoolchain

# Running the target on qemu
run:	$(KERNEL)
ifeq ($(EXEC),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mYou must specify a kernel to exec\e[0m\n"
	@exit 1
else
	@$(QEMU) $(QEMUFLAGS) -M ast2500-evb -cpu arm1176 -kernel $(EXEC)
endif