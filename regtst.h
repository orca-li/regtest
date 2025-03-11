#ifndef FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532
#define FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532

#ifndef REGTEST_MAJOR
#warning "REGTEST_MAJOR"
#define REGTEST_MAJOR 1
#endif
#ifndef REGTEST_MINOR
#warning "REGTEST_MINOR"
#define REGTEST_MINOR 0
#endif
#ifndef REGTEST_PATCH
#warning "REGTEST_PATCH"
#define REGTEST_PATCH 0
#endif

#define KILO_STEP_SIZE 1000ULL
#define KIBI_STEP_SIZE 1024ULL
#define KB (1 * KILO_STEP_SIZE)
#define MB (KB * KILO_STEP_SIZE)
#define GB (MB * KILO_STEP_SIZE)
#define TB (GB * KILO_STEP_SIZE)
#define KiB (1 * KIBI_STEP_SIZE)
#define MiB (KiB * KIBI_STEP_SIZE)
#define GiB (MiB * KIBI_STEP_SIZE)
#define TiB (GiB * KIBI_STEP_SIZE)

#ifndef EMULATOR_TEST_MEMORY
#warning "EMULATOR_TEST_MEMORY"
#define EMULATOR_TEST_MEMORY 0
#endif

#if EMULATOR_TEST_MEMORY
#define _POSIX_C_SOURCE 200809L
#include <time.h>

#ifndef DECELERATION_OF_TIME
#warning "DECELERATION_OF_TIME"
#define DECELERATION_OF_TIME 0
#endif
#endif

typedef unsigned long long regsize_t;

regsize_t regtst(char* reg, regsize_t regsz);

#endif /* FILE_UUID_fed2f221_eef3_4912_a186_e586433cd532 */