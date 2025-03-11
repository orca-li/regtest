v1.0.0
```
                       /   d8            d8   
888-~\  e88~~8e  e88~88e _d88__  d88~\ _d88__ 
888    d888  88b 888 888  888   C888    888   
888    8888__888 "88_88"  888    Y88b   888   
888    Y888    ,  /       888     888D  888   
888     "88___/  Cb       "88_/ \_88P   "88_/ 
                  Y8""8D                                                                     
```
# About
This library provides an API for testing registers during microcontroller boot. It can be used to test ROM, flash, and RAM, although it was initially created for RAM testing.

# Description
When powering up a microcontroller, it would be good to perform a memory test at least once. This library uses a classic read/write test, using the values 0x55 and 0xAA. You can write your own improved solutions based on this library. You will need to solve the problem of assembly inserts for your processor architecture for the SP and BSP registers yourself.

# Build

## Hello World

### Windows

Use cygwin or msys2. Then follow the Linux/MacOS instructions.

### Linux/MacOS

```bash
git clone https://github.com/orca-li/regtst.git
make
```

You can also add and change as you like.

```bash
make EMULATOR=1 DECELERATION=1
```

## Library Integration

```bash
git clone https://github.com/orca-li/regtst.git
make init
```

# API

Include the library in the file that will test the memory.

```c
#include "regtst.h"
```

Then use the memory test function.

```c
regsize_t regtst(char* reg, ramsize_t regsz);
```

The function returns the number of registers that failed the check. It also accepts a pointer to the beginning of the region under test and its size. The function prints through printf and uses escape sequences. You need to know that the function returns "!!" if the register is broken. Otherwise, the function can return the original register value, so there may be more than just zeros.
