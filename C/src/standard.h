#pragma once

#include <windows.h>
#include "shared/_comp_bass.h"

#define EXPORT    __declspec(dllexport)
#define RUNTIME
#define CWSTR     const wchar_t*

HMODULE self;

UINT Result;
BOOL IsInitialized = FALSE;

BOOL  IsCursorLocked = FALSE;
POINT CursorPos      = { .x = 0, .y = 0 };
RECT  CursorRect     = { 0 };

VOID RuntimeWarning() { if (!IsInitialized) printf("C-Runtime: Lib wasn't initialized. Some functions won't work\r\n"); }

VOID MakeDirs(const wchar_t* path) {
    wchar_t buffer[MAX_PATH];

    wcsncpy_s(buffer, MAX_PATH, path, _TRUNCATE);

    for (wchar_t* p = buffer; *p; p++) {
        if (*p == L'\\' || *p == L'/') {
            wchar_t old = *p;
            *p = L'\0';

            if (wcslen(buffer) > 3) {
                if (!CreateDirectoryW(buffer, NULL)) {
                    UINT error = GetLastError();
                    if (error != ERROR_ALREADY_EXISTS) {
                        printf("Failed to create the full directory: %d\r\n", error);
                        return;
                    }
                }
            }

            *p = old;
        }
    }
}