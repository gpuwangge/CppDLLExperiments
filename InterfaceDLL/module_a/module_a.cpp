#include "module_a_impl.h"
#include "module_a.h"
#include <iostream>
#include <sstream>

ModuleAImpl::ModuleAImpl() {
    std::cout << "ModuleA initialized" << std::endl;
}

std::string ModuleAImpl::processData(const std::string& data) {
    std::string result = "[" + name_ + "] processed: " + data;
    
    if (moduleB_) {
        std::cout << "ModuleA calling ModuleB" << std::endl;
        result = moduleB_->transformData(result);
    }
    
    return result; 
}

int ModuleAImpl::calculate(int a, int b) {
    int result = a + b;
    std::cout << "[" << name_ << "] calculated: " << a << " + " << b << " = " << result << std::endl;
    return result;
}

void ModuleAImpl::setModuleB(std::shared_ptr<IModuleB> moduleB) {
    moduleB_ = moduleB;
    std::cout << "[" << name_ << "] set ModuleB" << std::endl;
}

std::string ModuleAImpl::getName() const {
    return name_;
}

// 工厂函数实现
extern "C" MODULE_A_API std::shared_ptr<IModuleA> createModuleA() {
    return std::make_shared<ModuleAImpl>();
}