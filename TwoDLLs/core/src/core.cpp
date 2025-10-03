#include "core.h"
#include <iostream>
#include <sstream>

CoreSystem::CoreSystem() 
    : logCallback_(nullptr) {
    if (logCallback_) {
        logCallback_("CoreSystem constructed");
    } else {
        std::cout << "CoreSystem constructed" << std::endl;
    }
}

CoreSystem::~CoreSystem() {
    if (logCallback_) {
        logCallback_("CoreSystem destroyed");
    } else {
        std::cout << "CoreSystem destroyed" << std::endl;
    }
}

void CoreSystem::initialize() {
    log("CoreSystem initialized");
}

void CoreSystem::shutdown() {
    log("CoreSystem shutdown");
}

void CoreSystem::setUtilityFunctions(
    std::function<double(double, double)> mathFunc,
    std::function<std::string(const std::string&)> stringFunc) {
    
    mathFunction_ = mathFunc;
    stringFunction_ = stringFunc;
    log("Utility functions set");
}

double CoreSystem::processCalculation(double a, double b) {
    if (mathFunction_) {
        double result = mathFunction_(a, b);
        log("Calculation processed: " + std::to_string(a) + ", " + std::to_string(b) + " -> " + std::to_string(result));
        return result;
    } else {
        log("Math function not available");
        return 0.0;
    }
}

std::string CoreSystem::processString(const std::string& input) {
    if (stringFunction_) {
        std::string result = stringFunction_(input);
        log("String processed: '" + input + "' -> '" + result + "'");
        return result;
    } else {
        log("String function not available");
        return input;
    }
}

void CoreSystem::setLogCallback(LogCallback callback) {
    logCallback_ = callback;
    log("Log callback set");
}

void CoreSystem::log(const std::string& message) {
    if (logCallback_) {
        logCallback_("[Core] " + message);
    } else {
        std::cout << "[Core] " << message << std::endl;
    }
}

// C接口实现
extern "C" {
    CoreSystem* create_core_system() {
        return new CoreSystem();
    }
    
    void destroy_core_system(CoreSystem* system) {
        delete system;
    }
    
    void core_initialize() {
        std::cout << "[Core] Initialized via C interface" << std::endl;
    }
}