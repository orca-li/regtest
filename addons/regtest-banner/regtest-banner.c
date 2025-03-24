#if REGTEST_REGTEST_BANNER

#include "regtest-banner.h"
#include <stdio.h>

#define REGTEST_BANNER1 "                       /   d8                      d8\r\n"
#define REGTEST_BANNER2 "888-~\\  e88~~8e  e88~88e _d88__  e88~~8e   d88~\\ _d88__\r\n"
#define REGTEST_BANNER3 "888    d888  88b 888 888  888   d888  88b C888    888\r\n"
#define REGTEST_BANNER4 "888    8888__888 \"88_88\"  888   8888__888  Y88b   888\r\n"
#define REGTEST_BANNER5 "888    Y888    ,  /       888   Y888    ,   888D  888\r\n"
#define REGTEST_BANNER6 "888     \"88___/  Cb       \"88_/  \"88___/  \\_88P   \"88_/\r\n"
#define REGTEST_BANNER7 "                  Y8\"\"8D\r\n\r\n"


void regtestAddonsRegtestBanner(void)
{
    printf(REGTEST_BANNER1);
    printf(REGTEST_BANNER2);
    printf(REGTEST_BANNER3);
    printf(REGTEST_BANNER4);
    printf(REGTEST_BANNER5);
    printf(REGTEST_BANNER6);
    printf(REGTEST_BANNER7);
}

#endif