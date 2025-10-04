#pragma once

#include "../interface/imodule_a.h"
#include "../interface/imodule_b.h"
#include <memory>
#include <string>

class ModuleAImpl : public IModuleA {
private:
    std::shared_ptr<IModuleB> moduleB_;
    std::string name_ = "ModuleA";
    
public:
    ModuleAImpl();
    virtual ~ModuleAImpl() = default;
    
    std::string processData(const std::string& data) override;
    int calculate(int a, int b) override;
    void setModuleB(std::shared_ptr<IModuleB> moduleB) override;
    std::string getName() const override;
};