#include "regtest.h"
#include "addons/lib-addon/lib-addon.h"

#define RAM_SIZE 64

int main()
{
    uint8_t RAM[RAM_SIZE] = {0};

    if (regtest(RAM, RAM_SIZE))
        return 1;

    return 0;
}