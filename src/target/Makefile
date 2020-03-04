 #
# Makefile at target root, redirection from target
 #

export TARGET_DIR	:=	$(addprefix $(shell realpath .),	raspi)

# TODO: target base always functionnal
export TARGET_BASE	:=	$(shell echo "$(TARGET)" | sed 's/[0-9\-_]//g')

export ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(TARGET_DIR) .)

.PHONY: all	targetbuild

all:	setup	targetbuild

targetbuild:
	@make -C $(TARGET_BASE)/$(TARGET) --no-print-directory

setup:
	@mkdir -p $(KBUILD)
	@cp $(TARGET_BASE)/$(TARGET)/$(TGTLINKER) $(TGTLINKER_BUILD)