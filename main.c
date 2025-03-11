#if EMULATOR_TEST_MEMORY
#include <stdlib.h>
#define SRAND() srand(time(NULL))
#else
#define SRAND()
#endif

#include "regtst.h"


#define RAM_SIZE 64 * KiB

int main()
{
    char RAM[RAM_SIZE] = {0};

    SRAND();
    if (regtst(RAM, RAM_SIZE))
        return 1;

    return 0;
}