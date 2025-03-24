#if ADDONS_EXIT_BANNER

#include <stdio.h>
#include "exit-banner.h"
#include "addons/get-info/get-info.h"

void regtstAddonsExitBanner(uintmax_t errcnt, uintmax_t range, uint8_t* begin, uint8_t* end)
{
    static const int buffsz = 128;
    char buffer[buffsz];
    printf("Regtest has been completed!\r\n\r\n");

    printf("Range: %p => %p\r\n", begin, end - 1);
    printf("Total memory: %s\r\n", regtstLibAddonFmtBytes(buffer, range));
    printf("Faulty Registers: %ju\r\n\r\n", errcnt);

    printf("[CPU] %s %s %s @ %s\r\n", GETINFO_PRINT_NULL(gRegtestGetInfo.cpu.name), GETINFO_PRINT_NULL(gRegtestGetInfo.cpu.freq), GETINFO_PRINT_NULL(gRegtestGetInfo.cpu.core), GETINFO_PRINT_NULL(gRegtestGetInfo.cpu.vendor));
    printf("[RAM] %s %s @ %s\r\n", GETINFO_PRINT_NULL(gRegtestGetInfo.ram.name), GETINFO_PRINT_NULL(gRegtestGetInfo.ram.size), GETINFO_PRINT_NULL(gRegtestGetInfo.ram.vendor));;

    printf("Version: %d.%d.%d\r\n", REGTEST_MAJOR, REGTEST_MINOR, REGTEST_PATCH);
    printf("Vendor: %s\r\n", GETINFO_PRINT_NULL(gRegtestGetInfo.vendor));
    printf("License: %s\r\n\r\n", GETINFO_PRINT_NULL(gRegtestGetInfo.license));
    printf("Done!\r\n");
}

#endif