#include "mydll.h"
#include <cmath>

Calculator::Calculator() : precision_(2) {
    std::cout << "Calculator constructed!" << std::endl;
}

Calculator::~Calculator() {
    std::cout << "Calculator destroyed!" << std::endl;
}

double Calculator::add(double a, double b) {
    double result = a + b;
    // 简单处理精度
    double factor = std::pow(10.0, precision_);
    return std::round(result * factor) / factor;
}

double Calculator::multiply(double a, double b) {
    double result = a * b;
    double factor = std::pow(10.0, precision_);
    return std::round(result * factor) / factor;
}

void Calculator::setPrecision(int precision) {
    precision_ = (precision < 0) ? 0 : ((precision > 10) ? 10 : precision);
}

int Calculator::getPrecision() const {
    return precision_;
}

// C接口实现
extern "C" {
    double calculate_sum(double a, double b) {
        Calculator calc;
        return calc.add(a, b);
    }
    
    void initialize_calculator() {
        std::cout << "Calculator initialized via C interface!" << std::endl;
    }
}