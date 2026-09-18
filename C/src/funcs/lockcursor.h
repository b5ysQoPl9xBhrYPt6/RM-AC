#pragma once

#include "../export.h"

VOID C_ReLockCursorRuntime(IN BOOL lock) {
    RuntimeWarning();
    IsCursorLocked = lock;
    if (!lock) ClipCursor(NULL);
}
