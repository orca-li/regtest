#ifndef FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532
#define FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532

#ifndef REGTEST_MAJOR
#warning "REGTEST_MAJOR"
#define REGTEST_MAJOR 0
#endif
#ifndef REGTEST_MINOR
#warning "REGTEST_MINOR"
#define REGTEST_MINOR 0
#endif
#ifndef REGTEST_PATCH
#warning "REGTEST_PATCH"
#define REGTEST_PATCH 0
#endif

#ifndef EMULATOR_TEST_MEMORY
#warning "EMULATOR_TEST_MEMORY"
#define EMULATOR_TEST_MEMORY 0
#endif

#ifndef REGTST_ADDONS
#warning "REGTST_ADDONS"
#define REGTST_ADDONS 0
#endif

#if REGTST_ADDONS
#include "addons/addons.h"
#endif

typedef unsigned long long regsize_t;

regsize_t regtst(char* reg, regsize_t regsz);

#endif /* FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532 */