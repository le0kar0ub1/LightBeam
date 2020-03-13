 #
# Makefile at raspi target root, redirection from targetbase
 #

include $(MKHELPER_DIR)/macro.mk

all:	checkup	targetbuild

targetbuild:
	@make -C shared --no-print-directory
	@make -C $(TARGET) --no-print-directory

checkup:
ifeq ($(shell test -f $(TARGET)/$(TGTMACRO) && echo targetable), targetable)
	@cp $(TARGET)/$(TGTMACRO) $(TGTMACRO_BUILD)
	$(eval CCFLAGS += -imacros $(TGTMACRO_BUILD)/$(TGTMACRO))
else
	$(call RAISE, "Miss needed @config file for $(TARGET) target")
endif