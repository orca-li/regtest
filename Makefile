ADDONS ?=
EMULATOR ?=
DECELERATION ?=
EXIT_BANNER ?=
PROGRESS_DUMP ?=

VERSION_MAJOR := 1
VERSION_MINOR := 0
VERSION_PATCH := 0

VERSION := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

CC := clang

CC_INCLUDES += -I"."

CC_DEFINES += -D"REGTEST_MAJOR"=$(VERSION_MAJOR)
CC_DEFINES += -D"REGTEST_MINOR"=$(VERSION_MINOR)
CC_DEFINES += -D"REGTEST_PATCH"=$(VERSION_PATCH)

CC_FLAGS += $(CC_DEFINES)
CC_FLAGS += -Wall
CC_FLAGS += -Wextra
CC_FLAGS += -Werror
CC_FLAGS += -O3
ifeq ($(EMULATOR), 1)
CC_FLAGS += -D"EMULATOR_TEST_MEMORY"=1
else
CC_FLAGS += -D"EMULATOR_TEST_MEMORY"=0
endif
ifeq ($(DECELERATION), 1)
CC_FLAGS += -D"DECELERATION_OF_TIME"=1
else
CC_FLAGS += -D"DECELERATION_OF_TIME"=0
endif
ifeq ($(ADDONS), 1)
CC_FLAGS += -D"REGTST_ADDONS"=1
else
CC_FLAGS += -D"REGTST_ADDONS"=0
endif
ifeq ($(EXIT_BANNER), 1)
CC_FLAGS += -D"ADDONS_EXIT_BANNER"=1
CC_SOURCES += addons/exit-banner/exit-banner.c
else
CC_FLAGS += -D"ADDONS_EXIT_BANNER"=0
endif
ifeq ($(PROGRESS_DUMP), 1)
CC_FLAGS += -D"ADDONS_PROGRESS_DUMP"=1
CC_SOURCES += addons/progress-dump/progress-dump.c
else
CC_FLAGS += -D"ADDONS_PROGRESS_DUMP"=0
endif

CC_ASAN += -fsanitize=address,undefined,leak
CC_MSAN += -fsanitize=memory,undefined

CC_SOURCES += regtst.c
CC_SOURCES += main.c
CC_SOURCES += addons/lib-addon/lib-addon.c
CC_SOURCES += tests/00-test-55AA/00-test-55aa.c

TARGET := v$(VERSION)-regtst.out
BUILD := build

MD = mkdir
MD_FLAGS += -pv
RM := rm
RM_FLAGS += -rf
SLEEP := sleep 1

all:
	$(MD) $(MD_FLAGS) $(BUILD)
	$(CC) $(CC_INCLUDES) $(CC_FLAGS) $(CC_ASAN) $(CC_SOURCES) -o $(BUILD)/ASAN-$(TARGET)
	$(CC) $(CC_INCLUDES) $(CC_FLAGS) $(CC_MSAN) $(CC_SOURCES) -o $(BUILD)/MSAN-$(TARGET)

init: clean
	$(RM) $(RM_FLAGS) main.c

clean:
	$(RM) $(RM_FLAGS) $(BUILD)

test:
	@./$(BUILD)/ASAN-$(TARGET) || true
	@$(SLEEP)
	@./$(BUILD)/MSAN-$(TARGET) || true
