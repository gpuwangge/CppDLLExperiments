#pragma once

#ifdef MODULE_B_EXPORTS
#define MODULE_B_API __declspec(dllexport)
#else
#define MODULE_B_API __declspec(dllimport)
#endif

#include <memory>

class IModuleB;

extern "C" {
    MODULE_B_API std::shared_ptr<IModuleB> createModuleB();
}