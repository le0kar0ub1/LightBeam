 #
# Root Makefile project, calling sub-build
 #

sinclude mkhelper/def.mk
sinclude mkhelper/arch.mk
sinclude mkhelper/macro.mk
sinclude mkhelper/toolchain.mk
sinclude mkhelper/builder/def.mk

.PHONY: all _build fclean debug clean

all:	_prebuild	_build

# Evaluate if the build is correct
_prebuild:
	$(call EvalTargetMachine, $(TARGET))
	@echo -e "\n *"
	@echo -e "*  Building $(KERNEL)"
	@echo -e " *"

# Lauch the build, clean & exit if failed
_build:
	@make -s -C $(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(TARGET_DIR) --no-print-directory	\
		|| \
	(echo -e "[$(BoldRed)ABORT$(Blank)] Build Failed" && make -s fclean --no-print-directory && exit 0)

# Clean the relocatable objects & kbuild
clean:
	@$(RM) $(BUILDIR)

# Full clean the project directory
fclean:	clean
	@$(RM) $(PROJECT)*.bin $(PROJECT)*.img $(PROJECT)*.iso
	@$(RM) vgcore.* qemu_*.core
	@$(RM) $(shell find . -name *.dep)

# Build & check toolchain
toolchain:
	@./mktoolchain/mktoolchain

help:
	@echo "Handled target:"
	@echo "    $(HANDLED_PLATEFORM)"
