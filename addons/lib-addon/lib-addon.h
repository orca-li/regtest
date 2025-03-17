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

char* regtstAddonFmtBytes(char* str, uintmax_t bytes);

#endif /* FILE_UUID_b9a31947_a545_49b6_9f84_86d8bf879cce */