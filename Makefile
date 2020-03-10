 #
# Root Makefile project, calling sub-build
 #

include mkhelper/def.mk
include mkhelper/macro.mk
include mkhelper/toolchain.mk

.PHONY: all prebuld build fclean debug clean $(KERNEL)

all:	prebuild	build	$(KERNEL)

# Evaluate if the build is correct
prebuild:
	$(call EvalToolchain)
	$(call EvalTargetMachine, $(TARGET))
	@echo -e "\n *"
	@echo -e "*  Building $(KERNEL)"
	@echo -e " *\n"

# additionnal checkup
checkup:
	# $(call EvalTargetMachine, $(TARGET))
	# $(call EvalTargetProcessor, $(PROCESSOR))
	# $(call EvalTargetArch, $(ARCH))

# Lauch the build, clean & exit if failed
build:
	@make -C $(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(TARGET_DIR) --no-print-directory	\
		|| \
	(echo -e "[$(BoldRed)ABORT$(Blank)] Build Failed" && make fclean --no-print-directory && exit 0)

# Disassemble the kernel (debug)
disassemble: $(KERNEL)
	@$(AARCH64_OBJDMP) --no-show-raw-insn -d -Mintel $(PROJECT)-*$(BIN_EXTENSION) | source-highlight -s asm -f esc256 | less -eRiMX

re:	fclean all

# Clean the relocatable objects & kbuild
clean:
	@$(RM) $(BUILDIR)

# Full clean the projet
fclean:	clean
	@$(RM) $(PROJECT)*.bin $(PROJECT)*.img
	@$(RM) vgcore.* qemu_*.core
	@$(RM) $(shell find . -name $(BUILDEP))

# Build & check toolchain
toolchain:
	@./mktoolchain/mktoolchain

# Running the target on qemu
run:	$(KERNEL)
ifeq ($(EXEC),)
	@echo -e "[\e[91;1mFAIL\e[0m] \e[31mYou must specify a kernel to exec\e[0m\n"
	@exit 1
else
	@$(QEMU) $(QEMUFLAGS) -m 256 -M $(MACHINE) -cpu $(CPU) -kernel $(EXEC)
endif

utils:
	$(AARCH64_ARMGNUBASE)$(exec)