#if ADDONS_EXIT_BANNER

#include <stdio.h>
#include "exit-banner.h"

void regtstAddonsExitBanner(uintmax_t range, uint8_t* begin, uint8_t* end)
{
    static const int buffsz = 128;
    char buffer[buffsz];
    printf("Reg test has been completed!\r\n\r\n");
    printf("Range: %p => %p\r\n", begin, end - 1);
    printf("Total memory: %s\r\n", regtstLibAddonFmtBytes(buffer, range));
    printf("Version: %d.%d.%d\r\n", REGTEST_MAJOR, REGTEST_MINOR, REGTEST_PATCH);
    printf("MIT License\r\n");
    printf("Copyright(c) 2025 Orcali\r\n");
    printf("Done!\r\n");
}

#endif