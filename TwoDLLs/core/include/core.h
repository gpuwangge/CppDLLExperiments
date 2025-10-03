#pragma once

#ifdef _WIN32
    #ifdef COREDLL_EXPORTS
        #define CORE_API __declspec(dllexport)
    #else
        #define CORE_API __declspec(dllimport)
    #endif
#else
    #define CORE_API __attribute__((visibility("default")))
#endif

#include <string>
#include <functional>

// 前向声明，避免直接包含utils头文件
class CORE_API DataProcessor;

// 回调函数类型定义
typedef std::function<void(const std::string&)> LogCallback;

class CORE_API CoreSystem {
public:
    CoreSystem();
    ~CoreSystem();
    
    // 基础功能
    void initialize();
    void shutdown();
    
    // 设置工具模块的回调（解决循环依赖的关键）
    void setUtilityFunctions(
        std::function<double(double, double)> mathFunc,
        std::function<std::string(const std::string&)> stringFunc
    );
    
    // 使用工具功能
    double processCalculation(double a, double b);
    std::string processString(const std::string& input);
    
    // 设置日志回调
    void setLogCallback(LogCallback callback);
    
private:
    LogCallback logCallback_;
    std::function<double(double, double)> mathFunction_;
    std::function<std::string(const std::string&)> stringFunction_;
    
    void log(const std::string& message);
};

// 工厂函数 - 避免直接类依赖
extern "C" {
    CORE_API CoreSystem* create_core_system();
    CORE_API void destroy_core_system(CoreSystem* system);
    CORE_API void core_initialize();
}