#pragma once

#include <memory>
#include "imodule_a.h"
#include "imodule_b.h"

// 工厂函数声明
extern "C" {
    std::shared_ptr<IModuleA> createModuleA();
    std::shared_ptr<IModuleB> createModuleB();
}