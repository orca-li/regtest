#include "00-test-55aa.h"
#include "addons/lib-addon/lib-addon.h"
#include "addons/progress-dump/progress-dump.h"
#include "include/all.h"

uint8_t regtstRegStress8_Test55AA(uint8_t* const itr)
{
    uint8_t status = 0;
    regtstLibAddonAddressCtl(itr);

    if (regtstLibAddonCheckReg8(itr, 0x55, REGTST_STATUS_OK_REGISTER))
        status = 1;
    if (!status && regtstLibAddonCheckReg8(itr, 0xAA, REGTST_STATUS_REPEATE_PRINT_REGISTER))
        status = 1;

    regtstLibAddonSpaceCtl();

    return status;
}

uintmax_t regtst00TEST55AA(uint8_t* itr, uintmax_t range)
{
    uintmax_t errcnt = 0;

    while(range--)
        errcnt += regtstRegStress8_Test55AA(itr++);

    return errcnt;
}