 #
# Makefile at target root, redirection from target
 #

include $(MKHELPER_DIR)/macro.mk

export TARGET_DIR	:=	$(addprefix $(shell realpath .),	raspi)

# TODO: target base always functionnal
export TARGET_BASE	:=	$(shell echo "$(TARGET)" | sed 's/[0-9\-_]//g')

export ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(TARGET_DIR) .)

.PHONY: all	targetbaseBuild

all:	setup	targetbaseBuild

targetbaseBuild:
	@make -C $(TARGET_BASE) --no-print-directory

setup:
	@mkdir -p $(KBUILD)
ifeq ($(shell test -f $(TARGET_BASE)/$(TARGET)/$(TGTLINKER) && echo targetable), targetable)
	@cp $(TARGET_BASE)/$(TARGET)/$(TGTLINKER) $(TGTLINKER_BUILD)
else
	$(call RAISE, "No linker script to build the $(TARGET) target")
endif