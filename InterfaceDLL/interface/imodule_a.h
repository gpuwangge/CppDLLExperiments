#pragma once

#include <memory>
#include <string>

class IModuleB;  // 前向声明

class IModuleA {
public:
    virtual ~IModuleA() = default;
    
    virtual std::string processData(const std::string& data) = 0;
    virtual int calculate(int a, int b) = 0;
    virtual void setModuleB(std::shared_ptr<IModuleB> moduleB) = 0;
    virtual std::string getName() const = 0;
};