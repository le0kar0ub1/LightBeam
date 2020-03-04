 #
# Inc make which define macro for processus control
 #

include mkhelper/arch.mk

define RAISE
	@echo -e "[$(BoldRed)ABORT$(Blank)] $(1)"
	@exit 1
endef

define INFO
	@echo -e "[$(BoldBlue)LighBleam$(Blank)] $(1)"
endef

define EvalTargetProcessor
	$(if $(filter $(1),$(HANDLED_PROC)), $(call INFO, "Target processor $(1)"), $(call RAISE, "Invalid target processor"))
endef

define EvalTargetArch
	$(if $(filter $(1),$(HANDLED_ARCH)), $(call INFO, "Target architecture $(1)"), $(call RAISE, "Invalid target architecture"))
endef

define EvalTargetMachine
	$(if $(filter $(1),$(HANDLED_SYSTEM)), $(call INFO, "Target machine $(1)"), $(call RAISE, "Invalid target machine"))
endef

define EvalToolchain
	$(if $(filter $(PROJECT_PATH)/$(ARMGNUDIR), $(wildcard $(PROJECT_PATH)/$(ARMGNUDIR)/..)), $(call RAISE, "No GNU ARM toolchain -- make toolchain"), $(call INFO, "GNU ARM toolchain found"))
endef

# Check if Plateform is valid (target arg)
define EvalTargetBuild
	$(if $(PLATEFORM), $(call INFO, "Build for $(PLATEFORM) plateform"), $(call RAISE, "Invalid target plateform"))
endef