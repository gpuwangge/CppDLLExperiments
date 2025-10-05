#include "module_b_impl.h"
#include "module_b.h"
#include <iostream>
#include <algorithm>

ModuleBImpl::ModuleBImpl() {
    std::cout << "ModuleB initialized" << std::endl;
}

std::string ModuleBImpl::transformData(const std::string& data) {
    std::string result = "[" + name_ + "] transformed: " + data;
    
    if (moduleA_) {
        std::cout << "ModuleB calling ModuleA" << std::endl;
        int calculation = moduleA_->calculate(10, 20);
        result += " {calc: " + std::to_string(calculation) + "}";
    }
    
    // 转换为大写
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

double ModuleBImpl::compute(double value) {
    double result = value * 2.5;
    std::cout << "[" << name_ << "] computed: " << value << " * 2.5 = " << result << std::endl;
    return result;
}

void ModuleBImpl::setModuleA(std::shared_ptr<IModuleA> moduleA) {
    moduleA_ = moduleA;
    std::cout << "[" << name_ << "] set ModuleA" << std::endl;
}

std::string ModuleBImpl::getName() const {
    return name_;
}

// 工厂函数实现
extern "C" MODULE_B_API std::shared_ptr<IModuleB> createModuleB() {
    return std::make_shared<ModuleBImpl>(); 
}