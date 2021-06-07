#ifndef NUVOLA_HOOKS_HOOKMANAGER
#define NUVOLA_HOOKS_HOOKMANAGER

#include <vector>

class HookManager {
	static inline std::vector<class Hook*>* hooks = new std::vector<class Hook*>();
public:
	static void ApplyAll();
	static void ApplyHook(class Hook* toAdd);
};

#endif /* NUVOLA_HOOKS_HOOKMANAGER */
