#ifndef NUVOLA_HOOKS_HOOK
#define NUVOLA_HOOKS_HOOK

#include <string>
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>

#pragma comment(lib,"asmjit.lib")
#pragma comment(lib,"capstone.lib")
#pragma comment(lib,"PolyHook_2.lib")
#pragma comment(lib,"Zydis.lib")
#pragma comment(lib,"Zycore.lib")

class Hook {
	static inline PLH::CapstoneDisassembler* dis = new PLH::CapstoneDisassembler(PLH::Mode::x64);
	std::string name;
public:
	Hook(std::string name);
	auto GetName() -> std::string;
	auto GetDis() -> PLH::CapstoneDisassembler&;
	virtual auto Apply() -> bool;
};

#endif /* NUVOLA_HOOKS_HOOK */
