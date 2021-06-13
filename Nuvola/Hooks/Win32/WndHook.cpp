#include "WndHook.h"
#include <Windows.h>

WNDPROC oWndProc;

auto __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
{
	switch (uMsg)
	{
	case WM_KEYUP:
		std::cout << lParam << std::endl;
		break;
	case WM_KEYDOWN:
		std::cout << lParam << std::endl;
		break;
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


HWND g_HWND=NULL;
auto __stdcall EnumWindowsProcMy(HWND hwnd, LPARAM lParam) -> BOOL
{
    DWORD lpdwProcessId;
    GetWindowThreadProcessId(hwnd,&lpdwProcessId);
	if(hwnd==GetConsoleWindow()) {
		return TRUE;
	}
    if(lpdwProcessId==lParam)
    {
        g_HWND=hwnd;
        return FALSE;
    }
    return TRUE;
}

// this hook works across all versions cuz its hooking the native opengl dll, which is in all versions of the game
auto WndHook::Apply() -> bool {
	int procId = GetCurrentProcessId();
	EnumWindows(EnumWindowsProcMy, procId);
	if(g_HWND) {
		oWndProc = (WNDPROC)SetWindowLongPtrA(g_HWND, -4, (LONG_PTR)&WndProc);
		return true;
	}
	return false;
}

auto WndHook::Remove() -> bool {
	SetWindowLongPtr(g_HWND, -4, (LONG)(LONG_PTR)oWndProc);
	return true;
}