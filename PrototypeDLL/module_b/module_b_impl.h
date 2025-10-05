#pragma once

#include "../interface/imodule_a.h"
#include "../interface/imodule_b.h"
#include <memory>
#include <string>

class ModuleBImpl : public IModuleB {
private:
    std::shared_ptr<IModuleA> moduleA_;
    std::string name_ = "ModuleB";
    
public:
    ModuleBImpl();
    virtual ~ModuleBImpl() = default;
    
    std::string transformData(const std::string& data) override;
    double compute(double value) override;
    void setModuleA(std::shared_ptr<IModuleA> moduleA) override;
    std::string getName() const override;
};