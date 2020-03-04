 #
# Makefile at target root, redirection from target
 #

TARGET_DIR	:=	$(addprefix $(shell realpath .),	raspi)

TARGET_BASE	:=	$(shell echo "$(TARGET)" | sed 's/[0-9\-_]//g')

ROOT_PREFIX_BUILD	:=	$(shell realpath --relative-to $(TARGET_DIR) .)

.PHONY: all	targetbuild

all:	targetbuild

targetbuild:
	@make -C $(TARGET_BASE)/$(TARGET) --no-print-directory

# Savage method
.SECONDEXPANSION:
TARGET_BUILT_OBJECT	= 	$(shell find $(BUILDIR) -name '*$(EXTENSION_OBJ)')

$(KERNEL):	$(.SECONDEXPANSION)
	@$(CC) -o $(KERNEL) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e " LINKED      $@"

subBuild:
	@make -C $(TARGET) --no-print-directory