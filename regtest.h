#ifndef FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532
#define FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532

#include <stdint.h>

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

#include <stdint.h>

uintmax_t regtest(uint8_t* const start, uintmax_t range);

#endif /* FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532 */