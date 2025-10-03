#pragma once

#ifdef _WIN32
    #ifdef MYDLL_EXPORTS
        #define MYDLL_API __declspec(dllexport)
    #else
        #define MYDLL_API __declspec(dllimport)
    #endif
#else
    #define MYDLL_API __attribute__((visibility("default")))
#endif

#include <string>
#include <iostream>

class MYDLL_API Calculator {
public:
    Calculator();
    ~Calculator();
    
    double add(double a, double b);
    double multiply(double a, double b);
    void setPrecision(int precision);
    int getPrecision() const;
    
private:
    int precision_;
};

// C风格接口导出
extern "C" {
    MYDLL_API double calculate_sum(double a, double b);
    MYDLL_API void initialize_calculator();
}