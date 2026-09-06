#ifndef INITRUNTIMELIB_H

#include <stdio.h>
#include "..\export.h"

DWORD WINAPI ThMainLoop(IN LPVOID arg);
VOID CheckCursor();
VOID InitWarning();


UINT C_InitRuntimeLib() {
    HANDLE Thread = CreateThread(NULL, 0, ThMainLoop, NULL, 0, NULL);
    
    if (Thread == NULL) return GetLastError();
    CloseHandle(Thread);

    IsInitialized = TRUE;
    return 0;
}

DWORD WINAPI ThMainLoop(IN LPVOID arg) {
    printf("C-Runtime: MainLoop started\r\n");
    while (TRUE) {
        CheckCursor();
        Sleep(100);
    }

    return 0;
}


VOID CheckCursor() {
    GetClipCursor((LPRECT)&CursorRect);
    if (!IsCursorLocked) {
        GetCursorPos((LPPOINT)&CursorPos);
    } else {
        if ((CursorRect.right - CursorRect.left) > 1) {
            ClipCursor(&(const RECT){
                .left   = CursorPos.x,
                .right  = CursorPos.x + 1,
                .top    = CursorPos.y,
                .bottom = CursorPos.y + 1
            });
        }
    }
}

#endif