MakeClean:
	$(RM) $(RM_FLAGS) $(BUILD)

MakeBuildDir:
	$(MD) $(MD_FLAGS) $(BUILD)

RemoveTokenFile:
	@$(RM) $(RM_FLAGS) $(TOKENFILE)

MakeTokenFile: RemoveTokenFile
	@printf "%s = %s\n" $(foreach token,$(TOKENS),$(token) $(if $(strip $(value $(token))),$(value $(token)),\(null\))) > $(TOKENFILE)

MakeCompilation: $(MakeCompilationPrerequisites)

MakeCompilationDebug:
	$(TOOL) $(CC_ASAN) -o $(BUILD)/ASAN-$(OUTPUT)
	$(TOOL) $(CC_MSAN) -o $(BUILD)/MSAN-$(OUTPUT)

MakeCompilationRelease:
	$(TOOL) -o $(BUILD)/$(OUTPUT)

MakeTestAsan:
	@./$(BUILD)/ASAN-$(OUTPUT) || true

MakeTestSleep:
	@$(SLEEP)

MakeTestMsan:
	@./$(BUILD)/MSAN-$(OUTPUT) || true
