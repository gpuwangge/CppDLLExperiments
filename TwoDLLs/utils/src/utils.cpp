#include "utils.h"
#include "core.h"  // 现在可以包含core.h了，因为utils在core之后构建
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

UtilityManager::UtilityManager() 
    : coreSystem_(nullptr) {
    log("UtilityManager constructed");
}

UtilityManager::~UtilityManager() {
    log("UtilityManager destroyed");
}

void UtilityManager::initialize() {
    log("UtilityManager initialized");
}

void UtilityManager::setCoreSystem(CoreSystem* coreSystem) {
    coreSystem_ = coreSystem;
    log("Core system set in UtilityManager");
}

double UtilityManager::advancedCalculate(double a, double b) {
    double result = std::pow(a, b) + std::sqrt(a * b);
    log("Advanced calculation: " + std::to_string(a) + ", " + std::to_string(b) + " -> " + std::to_string(result));
    
    // 使用core system（如果可用）
    if (coreSystem_) {
        double coreResult = coreSystem_->processCalculation(a, b);
        log("Core system result: " + std::to_string(coreResult));
    }
    
    return result;
}

std::string UtilityManager::formatString(const std::string& input) {
    std::string result = "[" + input + "] formatted by utils";
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    log("String formatted: '" + input + "' -> '" + result + "'");
    
    // 使用core system（如果可用）
    if (coreSystem_) {
        std::string coreResult = coreSystem_->processString(input);
        log("Core system result: '" + coreResult + "'");
    }
    
    return result;
}

void UtilityManager::performComplexOperation() {
    log("Performing complex operation...");
    
    if (coreSystem_) {
        double calcResult = coreSystem_->processCalculation(10.5, 2.0);
        std::string stringResult = coreSystem_->processString("complex op");
        log("Complex operation completed: " + std::to_string(calcResult) + ", " + stringResult);
    } else {
        log("Core system not available for complex operation");
    }
}

void UtilityManager::log(const std::string& message) {
    std::cout << "[Utils] " << message << std::endl;
}

// C接口实现
extern "C" {
    double calculate_power(double base, double exponent) {
        return std::pow(base, exponent);
    }
    
    const char* reverse_string(const char* input) {
        static std::string result;
        result = input;
        std::reverse(result.begin(), result.end());
        return result.c_str();
    }
    
    void initialize_utilities() {
        std::cout << "[Utils] Utilities initialized via C interface" << std::endl;
    }
}