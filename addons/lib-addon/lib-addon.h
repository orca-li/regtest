#ifndef FILE_UUID_b9a31947_a545_49b6_9f84_86d8bf879cce
#define FILE_UUID_b9a31947_a545_49b6_9f84_86d8bf879cce

#include <stdint.h>

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

char* regtstLibAddonFmtBytes(char* str, uintmax_t bytes);
uint8_t regtstLibAddonCheckReg8(uint8_t* const itr, uint8_t value, uint8_t status);

#if REGTST_ADDONS
void regtstLibAddonBeforeTest(void);
#else
#define regtstLibAddonBeforeTest(...)
#endif

#endif /* FILE_UUID_b9a31947_a545_49b6_9f84_86d8bf879cce */