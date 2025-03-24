#if ADDONS_REGTEST_GET_INFO
#include <stdlib.h>
#include "get-info.h"

#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

#define MIT_LICENSE "MIT License Copyright (c) 2025 Orcali"
#define GET_LICENSE MIT_LICENSE
#ifdef REGTEST_GETINFO_VENDOR
#define GET_VENDOR TO_STRING(REGTEST_GETINFO_VENDOR)
#else
#define GET_VENDOR NULL
#endif

#ifdef REGTEST_GETINFO_CPUNAME
#define GET_CPU_NAME TO_STRING(REGTEST_GETINFO_CPUNAME)
#else
#define GET_CPU_NAME NULL
#endif
#ifdef REGTEST_GETINFO_CPUVENDOR
#define GET_CPU_VENDOR TO_STRING(REGTEST_GETINFO_CPUVENDOR)
#else
#define GET_CPU_VENDOR NULL
#endif
#ifdef REGTEST_GETINFO_CPUFREQ
#define GET_CPU_FREQ TO_STRING(REGTEST_GETINFO_CPUFREQ)
#else
#define GET_CPU_FREQ NULL
#endif
#ifdef REGTEST_GETINFO_CPUCORE
#define GET_CPU_CORE TO_STRING(REGTEST_GETINFO_CPUCORE)
#else
#define GET_CPU_CORE NULL
#endif

#ifdef REGTEST_GETINFO_RAMVENDOR
#define GET_RAM_VENDOR TO_STRING(REGTEST_GETINFO_RAMVENDOR)
#else
#define GET_RAM_VENDOR NULL
#endif
#ifdef REGTEST_GETINFO_RAMSIZE
#define GET_RAM_SIZE TO_STRING(REGTEST_GETINFO_RAMSIZE)
#else
#define GET_RAM_SIZE NULL
#endif
#ifdef REGTEST_GETINFO_RAMNAME
#define GET_RAM_NAME TO_STRING(REGTEST_GETINFO_RAMNAME)
#else
#define GET_RAM_NAME NULL
#endif

struct REGTEST_GET_INFO gRegtestGetInfo = {
    .vendor = GET_VENDOR,
    .license = GET_LICENSE,
    .cpu = {
        .name = GET_CPU_NAME,
        .vendor = GET_CPU_VENDOR,
        .freq = GET_CPU_FREQ,
        .core = GET_CPU_CORE,
    },
    .ram = {
        .name = GET_RAM_NAME,
        .vendor = GET_RAM_VENDOR,
        .size = GET_RAM_SIZE,
    },
};
#endif