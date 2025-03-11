#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "regtst.h"

static long LineCounter = 0;
static long SpaceCounter = 0;
static regsize_t BadRegisterCounter = 0;
static regsize_t BytesChecked = 0;

char* fmtbytes(char* str, regsize_t bytes)
{
    char* fmt = str;

    if (bytes < KiB)
        sprintf(str, "%lluB", bytes);
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


static void AddressCtl(const char* const itr)
{
    if (LineCounter++ == 0)
        printf("%p : ", itr);
}

static char GetByteValue(char* const itr)
{
    printf("%02hhx", *itr);
    fflush(stdout);
#if EMULATOR_TEST_MEMORY
#if DECELERATION_OF_TIME
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = 25000000L;
    nanosleep(&req, (struct timespec *)NULL);
#endif
    if ((double)rand() / RAND_MAX < 0.01)
        *itr ^= *itr;
#endif
    return *itr;
}

static void RewriteByteValue(char* const itr, const char value)
{
    *itr = value;
    printf("\b\b");
    fflush(stdout);
}

static void PrintBadByte(void)
{
    printf("\b\b!!");
    fflush(stdout);
    BadRegisterCounter++;
}

static void TestByteCtl(char* const itr)
{
    BytesChecked++;
    unsigned char org =  0;
    unsigned char temp = 0;
    org = GetByteValue(itr);
    RewriteByteValue(itr, 0x55);
    temp = GetByteValue(itr);
    if (temp != 0x55u)
        goto BadByteExit;
    RewriteByteValue(itr, 0xAA);
    temp = GetByteValue(itr);
    if (temp != 0xAAu)
        goto BadByteExit;
    RewriteByteValue(itr, org);
    temp = GetByteValue(itr);
    if (temp != org)
        goto BadByteExit;

    return;
BadByteExit:
    PrintBadByte();
}

static void SpaceCtl()
{
    if (SpaceCounter++ >= 1)
    {
        putchar(' ');
        SpaceCounter = 0;
    }
}

static void EndLineCtl()
{
    if (LineCounter > 15)
    {
        LineCounter = 0;
        printf("\r\n");
    }
}

static void PrintStart(void)
{
    printf("Starting Reg Test...\r\n");
}

static void PrintExit(regsize_t regsz, char* begin, char* end)
{
    static const int buffsz = 128;
    char buffer[buffsz];
    printf("Reg test has been completed!\r\n\r\n");
    printf("Range: %p => %p\r\n", begin, end - 1);
    printf("Total memory: %s\r\n", fmtbytes(buffer, regsz));
    printf("Dead registers: %lld\r\n\r\n", BadRegisterCounter);
    printf("Version: %d.%d.%d\r\n", REGTEST_MAJOR, REGTEST_MINOR, REGTEST_PATCH);
    printf("MIT License\r\n");
    printf("Copyright(c) 2025 Orcali\r\n");
    printf("Done!\r\n");
}

regsize_t regtst(char* reg, regsize_t regsz)
{
    char* itr = reg;

    PrintStart();

    for (regsize_t i = 0; i < regsz; i++)
    {
        AddressCtl(itr);
        TestByteCtl(itr++);
        SpaceCtl();
        EndLineCtl();
    }

    PrintExit(regsz, reg, itr);

    return BadRegisterCounter;
}