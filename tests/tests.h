#ifndef FILE_UUID_9f5c4675_9fd0_4461_9f68_508f16e16346
#define FILE_UUID_9f5c4675_9fd0_4461_9f68_508f16e16346

#ifndef TESTS_00_TEST_55AA
#define TESTS_00_TEST_55AA 1
#endif

#if TESTS_00_TEST_55AA
#include "00-test-55AA/00-test-55aa.h"
#ifndef TESTS_00_TEST_55AA_INDEX
#define TESTS_00_TEST_55AA_INDEX , 1
#elif TESTS_00_TEST_55AA_INDEX <= 0
#error "Non-valid index"
#endif
#define TESTS_00_TEST_55AA_COUNT +1
#define TESTS_00_TEST_55AA_SECTION , regtst00TEST55AA
#else
#define TESTS_00_TEST_55AA_COUNT +0
#define TESTS_00_TEST_55AA_SECTION
#define TESTS_00_TEST_55AA_INDEX
#endif

#if TESTS_01_TEST_FF00
#include "01-test-FF00/00-test-ff00.h"
#ifndef TESTS_01_TEST_FF00_INDEX
#define TESTS_01_TEST_FF00_INDEX , 2
#elif TESTS_01_TEST_FF00_INDEX <= 0
#error "Non-valid index"
#endif
#define TESTS_01_TEST_FF00_COUNT +1
#define TESTS_01_TEST_FF00_SECTION , regtst01TESTFF00
#else
#define TESTS_01_TEST_FF00_COUNT +0
#define TESTS_01_TEST_FF00_SECTION
#define TESTS_01_TEST_FF00_INDEX
#endif

#define TESTS_LIST_SIZE 1 TESTS_00_TEST_55AA_COUNT \
    TESTS_01_TEST_FF00_COUNT
#define TESTS_LIST_ARRAY NULL TESTS_00_TEST_55AA_SECTION \
    TESTS_01_TEST_FF00_SECTION
#define TESTS_LIST_ORDER 0 TESTS_00_TEST_55AA_INDEX  \
    TESTS_01_TEST_FF00_INDEX
#define TESTS_LIST_COUNT (TESTS_LIST_SIZE - 1)

typedef uintmax_t (*regtest_t)(uint8_t* itr, uintmax_t range);

#endif /* FILE_UUID_9f5c4675_9fd0_4461_9f68_508f16e16346 */