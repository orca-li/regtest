#ifndef FILE_UUID_81bc83ec_1464_40cf_9669_05e33c90a3b7
#define FILE_UUID_81bc83ec_1464_40cf_9669_05e33c90a3b7

#define REGTST_STATUS_OK_REGISTER 0
#define REGTST_STATUS_BAD_REGISTER 1
#define REGTST_STATUS_REPEATE_PRINT_REGISTER 2
#define REGTST_STATUS_REPEATE_PRINT_BAD_REGISTER 3

#if ADDONS_PROGRESS_DUMP
#include "../lib-addon/lib-addon.h"
void regtstAddonProgressDump(uint8_t* const itr, uint8_t status);
void regtstLibAddonAddressCtl(const uint8_t* const itr);
void regtstLibAddonSpaceCtl(void);
#else
#define regtstAddonProgressDump(...)
#define regtstLibAddonAddressCtl(...)
#define regtstLibAddonSpaceCtl(...)
#endif

#endif /* FILE_UUID_81bc83ec_1464_40cf_9669_05e33c90a3b7 */