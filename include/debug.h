#ifndef FILE_UUID_a517e508_c9a9_48f2_8808_4215afbecc3a
#define FILE_UUID_a517e508_c9a9_48f2_8808_4215afbecc3a

#if REGTEST_DEBUG
#include <stdio.h>
#include <stdint.h>
extern uintmax_t gDEBUG_errcnt;
#define gDEBUGerrcnt_ADD(_value) gDEBUG_errcnt += _value
#define gDEBUGerrcnt_PRINT() printf("real errcnt: %ju\r\n", gDEBUG_errcnt)
#else
#define gDEBUGerrcnt_ADD(...)
#define gDEBUGerrcnt_PRINT(...)
#endif

#endif /* FILE_UUID_a517e508_c9a9_48f2_8808_4215afbecc3a */