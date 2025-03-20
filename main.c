#if EMULATOR_TEST_MEMORY
#include <stdlib.h>
#define SRAND() srand(time(NULL))
#else
#define SRAND()
#endif

#include "regtst.h"
#include "addons/lib-addon/lib-addon.h"

#define RAM_SIZE 64

int main()
{
    uint8_t RAM[RAM_SIZE] = {0};

    if (regtst(RAM, RAM_SIZE))
        return 1;

    return 0;
}