 #
# Makefile at target root, redirection from target
 #

TARGET_DIR	:=	$(addprefix $(shell realpath .),	raspi)

# TODO: target base always functionnal
TARGET_BASE	:=	$(shell echo "$(TARGET)" | sed 's/[0-9\-_]//g')

ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(TARGET_DIR) .)

.PHONY: all	targetbuild

all:	setup	targetbuild		$(KERNEL)

targetbuild:
	@make -C $(TARGET_BASE)/$(TARGET) --no-print-directory

# Savage method
.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

$(KERNEL):	$(.SECONDEXPANSION)
	@$(CC) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

setup:
	@mkdir -p $(KBUILD)
	@cp $(TARGET_BASE)/$(TARGET)/$(TGTLINKER) $(TGTLINKER_BUILD)