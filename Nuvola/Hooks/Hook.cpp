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
auto Hook::Apply() -> bool
{
    return false;
}