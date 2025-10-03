#include "core.h"
#include "utils.h"
#include <iostream>
#include <memory>

// 全局日志回调
void global_log_callback(const std::string& message) {
    std::cout << "[App] " << message << std::endl;
}

int main() {
    std::cout << "=== Circular DLL Dependency Demo ===" << std::endl;
    std::cout << "Starting application..." << std::endl;
    
    // 初始化C接口
    core_initialize();
    initialize_utilities();
    
    // 创建Core系统
    std::cout << "\n1. Creating CoreSystem..." << std::endl;
    auto coreSystem = std::make_unique<CoreSystem>();
    coreSystem->setLogCallback(global_log_callback);
    coreSystem->initialize();
    
    // 创建工具管理器
    std::cout << "\n2. Creating UtilityManager..." << std::endl;
    auto utilsManager = std::make_unique<UtilityManager>();
    utilsManager->initialize();
    
    // 建立双向依赖
    std::cout << "\n3. Establishing circular dependencies..." << std::endl;
    
    // Core使用Utils的功能
    coreSystem->setUtilityFunctions(
        [](double a, double b) -> double {
            return calculate_power(a, b);  // 使用Utils的C接口
        },
        [](const std::string& input) -> std::string {
            return reverse_string(input.c_str());  // 使用Utils的C接口
        }
    );
    
    // Utils使用Core的功能
    utilsManager->setCoreSystem(coreSystem.get());
    
    // 测试功能
    std::cout << "\n4. Testing functionality..." << std::endl;
    
    // 测试Core使用Utils
    double calcResult = coreSystem->processCalculation(3.0, 4.0);
    std::cout << "Core calculation result: " << calcResult << std::endl;
    
    std::string stringResult = coreSystem->processString("hello world");
    std::cout << "Core string result: " << stringResult << std::endl;
    
    // 测试Utils使用Core
    double advancedResult = utilsManager->advancedCalculate(2.0, 3.0);
    std::cout << "Utils advanced calculation: " << advancedResult << std::endl;
    
    std::string formatted = utilsManager->formatString("test message");
    std::cout << "Utils formatted string: " << formatted << std::endl;
    
    // 复杂操作
    std::cout << "\n5. Performing complex operations..." << std::endl;
    utilsManager->performComplexOperation();
    
    // 清理
    std::cout << "\n6. Shutting down..." << std::endl;
    coreSystem->shutdown();
    
    std::cout << "\n=== Application finished successfully ===" << std::endl;
    return 0;
}