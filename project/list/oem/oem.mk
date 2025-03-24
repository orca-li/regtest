VENDOR := oem

ADDONS ?= 1
ifeq ($(ADDONS),1)
EXIT_BANNER ?= 1
PROGRESS_DUMP ?= 1
REGTEST_BANNER ?= 1
GET_INFO ?= 1
else
EXIT_BANNER ?= 0
PROGRESS_DUMP ?= 0
REGTEST_BANNER ?= 0
GET_INFO ?= 0
endif

GETINFO_CPUNAME := example
GETINFO_CPUFREQ := 1MHz
GETINFO_CPUCORE := example
GETINFO_CPUVENDOR := example
GETINFO_RAMNAME := example
GETINFO_RAMVENDOR := example
GETINFO_RAMSIZE := 1GiB

EMULATOR ?= 1
DECELERATION ?= 1