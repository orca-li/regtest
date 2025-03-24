#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib-addon.h"
#include "addons/progress-dump/progress-dump.h"
#include "include/all.h"

#if EMULATOR_TEST_MEMORY
#include <stdlib.h>
#define SRAND() srand(time(NULL))
#else
#define SRAND()
#endif

#if REGTEST_DEBUG
uintmax_t gDEBUG_errcnt = 0;
#endif

#if DECELERATION_OF_TIME
static void DeceleratinOfTimeHandle()
{
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = 60000000L;
    nanosleep(&req, (struct timespec *)NULL);
}
#else
#define DeceleratinOfTimeHandle(...)
#endif

#if EMULATOR_TEST_MEMORY
inline static void BreakByte(uint8_t* const itr)
{
    if ((double)rand() / RAND_MAX < 0.1)
    {
        gDEBUGerrcnt_ADD(1);
        *itr ^= *itr;
    }
}

static void EmulatorHandle(uint8_t* const itr)
{
    DeceleratinOfTimeHandle();
    BreakByte(itr);
}
#else
#define EmulatorHandle(...)
#endif

uint8_t regtstLibAddonCheckReg8(uint8_t* const itr, uint8_t value, uint8_t status)
{
    *itr = value;

    EmulatorHandle(itr);

    if (*itr != value)
    {
        if (status == REGTST_STATUS_OK_REGISTER)
            status = REGTST_STATUS_BAD_REGISTER;
        if (status == REGTST_STATUS_REPEATE_PRINT_REGISTER)
            status = REGTST_STATUS_REPEATE_PRINT_BAD_REGISTER;
    }

    regtstAddonProgressDump(itr, status);

    if (status != REGTST_STATUS_BAD_REGISTER && status != REGTST_STATUS_REPEATE_PRINT_BAD_REGISTER)
        status = REGTST_STATUS_OK_REGISTER;
    else
        status = REGTST_STATUS_BAD_REGISTER;

    return status;
}

char* regtstLibAddonFmtBytes(char* str, uintmax_t bytes)
{
    char* fmt = str;

    if (bytes < KiB)
        sprintf(str, "%juB", bytes);
    else if (bytes < MiB)
        sprintf(str, "%.1fKiB", (double)bytes / KiB);
    else if (bytes < GiB)
        sprintf(str, "%.1fMiB", (double)bytes / MiB);
    else if (bytes < TiB)
        sprintf(str, "%.1fGiB", (double)bytes / GiB);
    else
        sprintf(str, "%.1fTiB", (double)bytes / TiB);

    return fmt;
}

#if REGTST_ADDONS
void regtstLibAddonBeforeTest(void)
{
    SRAND();
}
#endif