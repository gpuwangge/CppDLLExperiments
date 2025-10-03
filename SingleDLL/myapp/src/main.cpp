// #include <iostream>
// int main(){
//     std::cout << "\nApplication finished successfully!" << std::endl;
//     return 0;
// }


#include "mydll.h"
#include <iostream>

void testCalculator() {
    std::cout << "=== Testing Calculator Class ===" << std::endl;
    
    Calculator calc;
    calc.setPrecision(3);
    
    std::cout << "Precision: " << calc.getPrecision() << std::endl;
    std::cout << "5.1234 + 3.4567 = " << calc.add(5.1234, 3.4567) << std::endl;
    std::cout << "2.5 * 4.2 = " << calc.multiply(2.5, 4.2) << std::endl;
}

void testCInterface() {
    std::cout << "\n=== Testing C Interface ===" << std::endl;
    
    initialize_calculator();
    double result = calculate_sum(10.5, 20.3);
    std::cout << "C interface sum: " << result << std::endl;
}

int main() {
    std::cout << "DLL Dependency Test Application" << std::endl;
    std::cout << "===============================" << std::endl;
    
    testCalculator();
    testCInterface();
    
    std::cout << "\nApplication finished successfully!" << std::endl;
    return 0;
}