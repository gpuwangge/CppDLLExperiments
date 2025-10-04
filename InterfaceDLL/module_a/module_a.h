#pragma once

#ifdef MODULE_A_EXPORTS
#define MODULE_A_API __declspec(dllexport)
#else
#define MODULE_A_API __declspec(dllimport)
#endif

#include <memory>

class IModuleA;

extern "C" {
    MODULE_A_API std::shared_ptr<IModuleA> createModuleA();
}