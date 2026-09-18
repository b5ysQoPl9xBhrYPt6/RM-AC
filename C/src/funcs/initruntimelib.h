#pragma once

#include <stdio.h>
#include "../export.h"
#include "../resources.h"

DWORD WINAPI ThMainLoop(IN LPVOID arg);
VOID CheckCursor();
VOID LoadResources();

UINT C_InitRuntimeLib() {
    LoadResources();
    // HANDLE Thread = CreateThread(NULL, 0, ThMainLoop, NULL, 0, NULL);
    
    // if (!Thread) return GetLastError();
    // CloseHandle(Thread);

    // IsInitialized = TRUE;
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

VOID LoadResources() {
    HRSRC res = FindResourceA(self, "bass.dll", RT_RCDATA);
    if (!res) {
        printf("FindResourceA('bass.dll') failed: %d\r\n", GetLastError());
        return;
    }

    HGLOBAL data = LoadResource(self, res);
    if (!data) {
        printf("LoadResource('bass.dll') failed: %d\r\n", GetLastError());
        return;
    }

    DWORD size = SizeofResource(self, res);
    VOID*  ptr = LockResource(data);

    printf("BASS size: %d bytes\r\n", size);

    wchar_t* LibPath = L"";  // Here is the temp file path
    MakeDirs(LibPath);
    FILE* f = _wfopen(LibPath, L"wb");
    if (!f) {
        printf("_wfopen failed\r\n");
        return;
    }

    fwrite(data, 1, size, f);
    fclose(f);
}