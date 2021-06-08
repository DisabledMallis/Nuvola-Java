#include "Hook.h"

Hook::Hook(std::string name)
{
    this->name = name;
}
auto Hook::GetName() -> std::string
{
    return this->name;
}
auto Hook::GetDis() -> PLH::CapstoneDisassembler&
{
    return *dis;
}
auto Hook::GetDetour() -> PLH::x64Detour* {
	return this->detour;
}
auto Hook::CreateDetour(const uint64_t fnAddress, const uint64_t fnCallback, uint64_t* userTrampVar) -> PLH::x64Detour* {
	this->detour = new PLH::x64Detour(fnAddress, fnCallback, userTrampVar, this->GetDis());
	return this->detour;
}
auto Hook::Apply() -> bool
{
    return false;
}
auto Hook::Remove() -> bool
{
    return false;
}