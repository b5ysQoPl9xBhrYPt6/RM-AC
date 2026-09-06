#ifndef STANDARD_H
#define STANDARD_H

#include <windows.h>

#define EXPORT    __declspec(dllexport)
#define RUNTIME
#define CWSTR     const wchar_t*

UINT Result;
BOOL IsInitialized = FALSE;

BOOL  IsCursorLocked = FALSE;
POINT CursorPos      = { .x = 0, .y = 0 };
RECT  CursorRect     = { 0 };

VOID RuntimeWarning() { if (!IsInitialized) printf("C-Runtime: Lib was not initialized. Runtime functions will not work\r\n"); }

#endif