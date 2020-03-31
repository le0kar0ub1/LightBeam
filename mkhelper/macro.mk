 #
# Inc make which define macro for processus control
 #

sinclude $(MKHELPER_DIR)/arch.mk

define RAISE
	@echo -e "[$(BoldRed)ABORTED$(Blank)]$(1)"
	@exit 1
endef

define INFO
	@echo -e "[$(BoldBlue)LighBleam$(Blank)]$(1)"
endef

define EvalTargetProcessor
	$(if $(filter $(1),$(HANDLED_PROC)), $(call INFO, "Target processor $(1)"), $(call RAISE, "Invalid target processor $(1)"))
endef

define EvalTargetArch
	$(if $(filter $(1),$(HANDLED_ARCH)), $(call INFO, "Target architecture $(1)"), $(call RAISE, "Invalid target architecture $(1)"))
endef

define EvalTargetMachine
	$(if $(filter $(1),$(HANDLED_PLATEFORM)), $(call INFO, "Target machine $(1)"), $(call RAISE, "Invalid target machine $(1)"))
endef

define EvalToolchain
	$(if $(filter $(PROJECT_PATH)/$(AARCH32_ARMGNUDIR), $(wildcard $(PROJECT_PATH)/$(AARCH32_ARMGNUDIR)/..)), $(call RAISE, "No GNU ARM NEABI toolchain -- make toolchain"), $(call INFO, "GNU ARM aarch32 toolchain found"))
	$(if $(filter $(PROJECT_PATH)/$(AARCH64_ARMGNUDIR), $(wildcard $(PROJECT_PATH)/$(AARCH64_ARMGNUDIR)/..)), $(call RAISE, "No GNU ARM AARCH toolchain -- make toolchain"), $(call INFO, "GNU ARM aarch64 toolchain found"))
endef

# Check if Plateform is valid (target arg)
define EvalTargetBuild
	$(if $(TARGET), $(call INFO, "Build for $(TARGET) target"), $(call RAISE, "Invalid target target"))
endef
