 #
# Makefile at raspi target root, redirection from targetbase
 #

include $(MKHELPER_DIR)/macro.mk

PREFIX_TARGET_DEPTH	:=	../

export TARGET_SOURCE_DIR	=	$(addprefix $(PREFIX_TARGET_DEPTH)shared/,	\
													.						\
													core					\
													driver					\
													tool					\
													lib						\
													init					\
								)

export TARGET_PREBUILD		=	$(wildcard \
										$(addsuffix /*$(EXTENSION_OBJ),	\
												$(addprefix $(realpath shared)/, \
												font)						\
										)								\
								)


all:	checkup	targetbuild

targetbuild:
	@make -C $(TARGET) --no-print-directory

checkup:
ifeq ($(shell test -f $(TARGET)/$(TGTMACRO) && echo targetable), targetable)
	@cp $(TARGET)/$(TGTMACRO) $(TGTMACRO_BUILD)
	$(eval CCFLAGS += -imacros $(TGTMACRO_BUILD)/$(TGTMACRO))
else
	$(call RAISE, "Miss needed @config file for $(TARGET) target")
endif

# fontbuild:
#	 @$(AARCH64_LD) -r -b binary -o font.o font.psf