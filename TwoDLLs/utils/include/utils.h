#pragma once

#ifdef _WIN32
    #ifdef UTILSDLL_EXPORTS
        #define UTILS_API __declspec(dllexport)
    #else
        #define UTILS_API __declspec(dllimport)
    #endif
#else
    #define UTILS_API __attribute__((visibility("default")))
#endif

#include <string>
#include <functional>

// 前向声明Core系统中的类
class CoreSystem;

class UTILS_API UtilityManager {
public:
    UtilityManager();
    ~UtilityManager();
    
    void initialize();
    void setCoreSystem(CoreSystem* coreSystem);
    
    // 工具函数
    double advancedCalculate(double a, double b);
    std::string formatString(const std::string& input);
    void performComplexOperation();
    
private:
    CoreSystem* coreSystem_;
    
    void log(const std::string& message);
};

// 独立的工具函数
extern "C" {
    UTILS_API double calculate_power(double base, double exponent);
    UTILS_API const char* reverse_string(const char* input);
    UTILS_API void initialize_utilities();
}