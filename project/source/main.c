#include <stdio.h>
#include "regtest.h"
#include "addons/lib-addon/lib-addon.h"

#define RAM_SIZE 64

int main()
{
    uint8_t RAM[RAM_SIZE] = {0};

    printf("retval: %ju\r\n", regtest(RAM, RAM_SIZE));

    return 0;
}