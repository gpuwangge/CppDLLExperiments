#pragma once

#include <memory>
#include <string>

class IModuleA;  // 前向声明

class IModuleB {
public:
    virtual ~IModuleB() = default;
    
    virtual std::string transformData(const std::string& data) = 0;
    virtual double compute(double value) = 0;
    virtual void setModuleA(std::shared_ptr<IModuleA> moduleA) = 0;
    virtual std::string getName() const = 0;
};