from pathlib import Path
from time import sleep
import ctypes as c

HERE = Path(__file__).resolve().parent
LIB_PATH = HERE / ".." / "ExternRuntime.dll"

runtime  = c.CDLL(LIB_PATH.as_posix())
functype = c.CFUNCTYPE

C_InitRuntimeLib        = functype(c.c_uint)(("C_InitRuntimeLib", runtime))
C_ReLockCursorRuntime   = functype(None, c.c_bool)(("C_ReLockCursorRuntime", runtime))
C_ReShowSafeMessage     = functype(c.c_uint, *(c.c_wchar_p, c.c_wchar_p, c.c_uint))(("C_ReShowSafeMessage", runtime))

def main():
    C_InitRuntimeLib()
    C_ReShowSafeMessage("Hello world!", "Message from C", 0x00000040)
    
    sleep(0.5)

if __name__ == "__main__":
    main()