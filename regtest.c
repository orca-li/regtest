#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "regtest.h"
#include "addons/addons.h"
#include "tests/tests.h"

static regtest_t tests[TESTS_LIST_SIZE] = {TESTS_LIST_ARRAY};
static uint8_t tests_order[TESTS_LIST_SIZE] = {TESTS_LIST_ORDER};

static uintmax_t TestRun(uint8_t* const itr, uintmax_t range)
{
    uintmax_t errcnt = 0;

    for(int i = 1; i < TESTS_LIST_SIZE; i++)
    errcnt += tests[tests_order[i]](itr, range);

    return errcnt;
}

uintmax_t regtest(uint8_t* const start, uintmax_t range)
{
    uintmax_t errcnt = 0;
    uint8_t* itr = start;

    regtestAddonsRegtestBanner();

    regtstLibAddonBeforeTest();

    errcnt = TestRun(itr, range);
    itr += range;

    regtstAddonsExitBanner(range, start, itr);

    return errcnt;
}