#ifndef NUVOLA_HOOKS_WIN32_WNDHOOK
#define NUVOLA_HOOKS_WIN32_WNDHOOK

#include "../Hook.h"

class WndHook : public Hook {
public:
	WndHook() : Hook("WndProc")
	{}
	auto Apply() -> bool override;
	auto Remove() -> bool override;
};


#endif /* NUVOLA_HOOKS_WIN32_WNDHOOK */
