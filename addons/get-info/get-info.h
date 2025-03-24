#ifndef FILE_UUID_191a6f60_2be5_4937_b14e_32c2f040d873
#define FILE_UUID_191a6f60_2be5_4937_b14e_32c2f040d873

#if ADDONS_REGTEST_GET_INFO
#include <stdint.h>

struct REGTEST_GET_INFO {
    const char* vendor;
    const char* license;
    struct REGTEST_GET_INFO_CPU {
        const char* vendor;
        const char* name;
        const char* freq;
        const char* core;
    } cpu;
    struct REGTEST_GET_INFO_RAM {
        const char* vendor;
        const char* name;
        const char* size;
    } ram;
};

extern struct REGTEST_GET_INFO gRegtestGetInfo;

#define GETINFO_PRINT_NULL(_arg) ((_arg) ? _arg : "Unknown" )
#else
#define GETINFO_PRINT_NULL(...) "unsupported"
#define GETINFO_FAULTY_REGISTERS 0
#endif



#endif /* FILE_UUID_191a6f60_2be5_4937_b14e_32c2f040d873 */