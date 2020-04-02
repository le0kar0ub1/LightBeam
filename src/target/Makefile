 #
# Makefile at target root, redirection from target
 #

sinclude $(MKHELPER_DIR)/macro.mk

# TODO: target base always functionnal

.PHONY: all	targetBuild

all:	setup	targetBuild

targetBuild:
	@make -s -C $(TARGET) --no-print-directory

setup:
	@mkdir -p $(BUILDNEED)
ifeq ($(shell test -f $(TARGET)/$(TGTLINKER) && echo targetable), targetable)
	@cp $(TARGET)/$(TGTLINKER) $(TGTLINKER_BUILD)
else
	$(call RAISE, "No linker script to build the $(TARGET) target")
endif
ifeq ($(shell test -f $(TARGET)/$(TGTMACRO) && echo targetable), targetable)
	@cp $(TARGET)/$(TGTMACRO) $(TGTMACRO_BUILD)
	$(eval CCFLAGS += -imacros $(TGTMACRO_BUILD)/$(TGTMACRO))
else
	$(call RAISE, "Miss needed @config file for $(TARGET) target")
endif