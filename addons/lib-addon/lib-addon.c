#include <stdio.h>
#include "lib-addon.h"

char* regtstAddonFmtBytes(char* str, uintmax_t bytes)
{
    char* fmt = str;

    if (bytes < KiB)
        sprintf(str, "%juB", bytes);
    else if (bytes < MiB)
        sprintf(str, "%.1fKiB", (double)bytes / KiB);
    else if (bytes < GiB)
        sprintf(str, "%.1fMiB", (double)bytes / MiB);
    else if (bytes < TiB)
        sprintf(str, "%.1fGiB", (double)bytes / GiB);
    else
        sprintf(str, "%.1fTiB", (double)bytes / TiB);

    return fmt;
}
