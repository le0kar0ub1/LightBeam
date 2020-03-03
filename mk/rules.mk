 #
# Inc make which define macro for processus control
 #

include mk/arch.mk

define RAISE
	@echo -e "[\e[91;1mABORT\e[0m] $(1)"
	@exit 1
endef

define INFO
	@echo -e "[\e[0;34mLighBleam\e[0m] $(1)"
endef

define EvalTargetProcessor
	$(if $(filter $(1),$(HANDLED_PROC)), $(call INFO, "Target processor $(1)"), $(call RAISE, "Invalid target processor"))
endef

define EvalTargetArch
	$(if $(filter $(1),$(HANDLED_ARCH)), $(call INFO, "Target architecture $(1)"), $(call RAISE, "Invalid target architecture"))
endef

define EvalTargetMachine
	$(if $(filter $(1),$(HANDLED_MACHINE)), $(call INFO, "Target machine $(1)"), $(call RAISE, "Invalid target machine"))
endef