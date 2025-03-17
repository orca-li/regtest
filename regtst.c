#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "regtst.h"
#include "addons/addons.h"

static long LineCounter = 0;
static long SpaceCounter = 0;
static regsize_t BadRegisterCounter = 0;
static regsize_t BytesChecked = 0;

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

    regtstAddonsExitBanner(regsz, reg, itr);

    return BadRegisterCounter;
}