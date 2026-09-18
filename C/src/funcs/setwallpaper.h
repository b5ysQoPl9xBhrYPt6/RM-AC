#pragma once

#include "../export.h"

UINT C_ReSetWallpaper(IN CWSTR imagePath) {
    RuntimeWarning();
    
    Result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (PVOID)imagePath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    if (Result == 0) return GetLastError();
    return 0;
}
