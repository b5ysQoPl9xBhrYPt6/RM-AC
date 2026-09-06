#ifndef SHOWSAFEMESSAGE_H
#define SHOWSAFEMESSAGE_H

#include "..\export.h"

typedef struct {
    wchar_t* MessageContent;
    wchar_t* MessageTitle;
    UINT  Style;
} __THREAD_ARGS;

DWORD WINAPI ThMessageBox(IN LPVOID arg);

UINT C_ReShowSafeMessage(IN wchar_t* content, IN wchar_t* title, IN UINT style) {
    __THREAD_ARGS* Data = malloc(sizeof(*Data));
    
    Data->MessageContent = malloc((wcslen(content) + 1) * sizeof(wchar_t));
    Data->MessageTitle   = malloc((wcslen(title) + 1) * sizeof(wchar_t));
    
    wcscpy(Data->MessageContent, content);
    wcscpy(Data->MessageTitle, title);
    Data->Style = style;

    HANDLE Thread = CreateThread(NULL, 0, ThMessageBox, Data, 0, NULL);
    
    if (Thread == NULL) {
        free(Data->MessageContent);
        free(Data->MessageTitle);
        free(Data);

        return GetLastError();
    }
    CloseHandle(Thread);

    return 0;
}

DWORD WINAPI ThMessageBox(IN LPVOID arg) {
    __THREAD_ARGS* Data = (__THREAD_ARGS*)arg;
    MessageBoxW(0, Data->MessageContent, Data->MessageTitle, Data->Style | MB_DEFAULT_DESKTOP_ONLY | MB_TOPMOST);
    
    free(Data->MessageContent);
    free(Data->MessageTitle);
    free(Data);

    return 0;
}

#endif