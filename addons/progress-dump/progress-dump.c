#if ADDONS_PROGRESS_DUMP && REGTST_ADDONS
#include <stdio.h>
#include "tests/tests.h"
#include "addons/progress-dump/progress-dump.h"

struct PROGRESS_DUMP_CTL {
    uintmax_t line;
    uintmax_t space;
} static ProgressDumpCtl = {
    .line = 0,
    .space = 0
};

static void AddressCtl(const uint8_t* const itr)
{
    if (ProgressDumpCtl.line++ == 0)
        printf("%p : ", itr);
}

static void PrintRegValue(const uint8_t* const itr, uint8_t status)
{
    if (status == REGTST_STATUS_OK_REGISTER)
        printf("%02hhx", *itr);
    else if (status == REGTST_STATUS_REPEATE_PRINT_REGISTER)
        printf("\b\b%02hhx", *itr);
    fflush(stdout);
}

static void PrintBadReg(uint8_t status)
{
    printf("%s", (status == REGTST_STATUS_BAD_REGISTER) ? "!!" :"\b\b!!");
    fflush(stdout);
}

static void StatusCtl(const uint8_t* const itr, uint8_t status)
{
    if (status == REGTST_STATUS_BAD_REGISTER || status == REGTST_STATUS_REPEATE_PRINT_BAD_REGISTER)
        PrintBadReg(status);
    else
        PrintRegValue(itr, status);
}

static void SpaceCtl(void)
{
    if (ProgressDumpCtl.space++ < 1)
        return;

    putchar(' ');
    ProgressDumpCtl.space = 0;
}

static void EndLineCtl()
{
    if (ProgressDumpCtl.line <= 15)
        return;
    ProgressDumpCtl.line = 0;
    printf("\r\n");
}

void regtstAddonProgressDump(uint8_t* const itr, uint8_t status)
{
    StatusCtl(itr, status);
}

void regtstLibAddonAddressCtl(const uint8_t* const itr)
{
    AddressCtl(itr);
}

void regtstLibAddonSpaceCtl(void)
{
    SpaceCtl();
    EndLineCtl();
}
#endif