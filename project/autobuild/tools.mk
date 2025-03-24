# Utils
CC := clang

CC_INCLUDES += -I"."

ifeq ($(TARGET), DEBUG)
CC_FLAGS += -O0
CC_FLAGS += -ggdb
MakeCompilationPrerequisites := MakeCompilationDebug
else
TARGET := RELEASE
CC_FLAGS += -O3
MakeCompilationPrerequisites := MakeCompilationRelease
endif

CC_DEFINES += -D"REGTEST_MAJOR"=$(VERSION_MAJOR)
CC_DEFINES += -D"REGTEST_MINOR"=$(VERSION_MINOR)
CC_DEFINES += -D"REGTEST_PATCH"=$(VERSION_PATCH)

CC_FLAGS += -Wall
CC_FLAGS += -Wextra
CC_FLAGS += -Werror

ifeq ($(TARGET), DEBUG)
CC_ASAN += -fsanitize=address,undefined,leak
CC_MSAN += -fsanitize=memory,undefined
endif

MD = mkdir
MD_FLAGS += -pv

RM := rm
RM_FLAGS += -rf

SLEEP := sleep 1

ECHO := echo

TOOL := $(CC) $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $(CC_SOURCES)

# Path
BUILD := build

TOKENFILE := $(BUILD)/Token.txt

OUTPUT := $(VENDOR)-v$(VERSION)-regtst.out