 #
# Inc make which define macro for processus control
 #

sinclude $(MKHELPER_DIR)/arch.mk

define RAISE
	@echo -e "[$(BoldRed)ABORTED$(Blank)]$(1)"
	@exit 1
endef

define INFO
	@echo -e "[$(BoldBlue)LIGHTBEAM$(Blank)]$(1)"
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

define EvalToolChainExistence
	$(if $(filter $(PROJECT_PATH)/$(2), $(wildcard $(PROJECT_PATH)/$(2)/..)), $(call RAISE, "No GNU $(1) toolchain -- make toolchain"), $(call INFO, "GNU $(1) toolchain found"))
endef

define EvalBinaryExistence
	$(if $(shell which $(1) 2> /dev/null),$(call INFO, Dependency found $(BoldMagenta)$(shell basename $(1))$(Blank)),$(call RAISE, Dependency not found $(BoldRed)$(shell basename $(1))$(Blank)))
endef

# Check if Plateform is valid (target arg)
define EvalTargetBuild
	$(if $(TARGET), $(call INFO, "Build for $(TARGET) target"), $(call RAISE, "Invalid target target"))
endef
