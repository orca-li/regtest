#ifndef FILE_UUID_d3fd6b08_4ebd_4851_abff_cd417c8e4908
#define FILE_UUID_d3fd6b08_4ebd_4851_abff_cd417c8e4908

#if ADDONS_EXIT_BANNER
#include "../lib-addon/lib-addon.h"

void regtstAddonsExitBanner(uint64_t regsz, char* begin, char* end);

#else
#define regtstAddonsExitBanner(...)
#endif

#endif /* FILE_UUID_d3fd6b08_4ebd_4851_abff_cd417c8e4908 */