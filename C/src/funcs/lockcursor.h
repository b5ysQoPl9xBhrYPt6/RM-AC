#ifndef LOCKCURSOR_H
#define LOCKCURSOR_H

#include "..\export.h"

VOID C_ReLockCursorRuntime(IN BOOL lock) {
    RuntimeWarning();
    IsCursorLocked = lock;
    if (!lock) ClipCursor(NULL);
}

#endif