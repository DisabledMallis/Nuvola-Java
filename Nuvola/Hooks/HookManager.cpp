#include "HookManager.h"
#include <iostream>

#include "OpenGL/GLHook.h"
#include "Win32/WndHook.h"

void HookManager::ApplyAll()
{
    HookManager::ApplyHook(new GLHook());
    HookManager::ApplyHook(new WndHook());
}

void HookManager::ApplyHook(Hook* toAdd)
{
    if(toAdd->Apply())
    {
        HookManager::hooks->push_back(toAdd);
        std::cout << "Successfully applied \'" << toAdd->GetName() << "\' patch!" << std::endl;
    }
    else
    {
        std::cout << "Failed to apply patch: " << toAdd->GetName() << std::endl;
	}
};