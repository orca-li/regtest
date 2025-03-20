include project/target.mk
include project/autobuild/version.mk
include project/autobuild/tokens.mk
include project/autobuild/tools.mk
include project/autobuild/prerequisites.mk

main: $(MAIN)
	@$(ECHO)

test: $(TEST)
	@$(ECHO)

include project/autobuild/targets.mk