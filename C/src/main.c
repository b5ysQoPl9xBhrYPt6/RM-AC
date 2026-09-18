#define LIB_BASS_DYNAMIC_LOAD

#include <windows.h>
#include <stdio.h>

#include "standard.h"

#include "funcs/initruntimelib.h"
#include "funcs/lockcursor.h"
#include "funcs/showsafemessage.h"
#include "funcs/setwallpaper.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        self = hinstDLL;
    }

    return TRUE;
}