#include <iostream>
#include <memory>
#include <windows.h>
#include "../interface/factory.h"

// 定义函数指针类型
typedef std::shared_ptr<IModuleA> (*CreateModuleAFunc)();
typedef std::shared_ptr<IModuleB> (*CreateModuleBFunc)();

int main() {
    std::cout << "=== Module App Launch ===" << std::endl;
    
    // 设置DLL搜索路径
    SetDllDirectoryA("");
    
    // 加载DLLs
    HMODULE moduleADll = LoadLibraryA("module_a.dll");
    HMODULE moduleBDll = LoadLibraryA("module_b.dll");
    
    if (!moduleADll || !moduleBDll) {
        std::cerr << "Failed to load DLLs" << std::endl;
        return -1;
    }
    
    // 获取工厂函数
    CreateModuleAFunc createA = (CreateModuleAFunc)GetProcAddress(moduleADll, "createModuleA");
    CreateModuleBFunc createB = (CreateModuleBFunc)GetProcAddress(moduleBDll, "createModuleB");
    
    if (!createA || !createB) {
        std::cerr << "Failed to get factory functions" << std::endl;
        return -1;
    }
    
    // 创建模块实例
    auto moduleA = createA();
    auto moduleB = createB();
    
    // 设置互相引用
    moduleA->setModuleB(moduleB);
    moduleB->setModuleA(moduleA);
    
    // 使用模块功能
    std::cout << "\n=== Test Begin ===" << std::endl;
    
    std::string result1 = moduleA->processData("Hello World");
    std::cout << "ModuleA Result: " << result1 << std::endl;
    
    std::string result2 = moduleB->transformData("Test Data");
    std::cout << "ModuleB Result: " << result2 << std::endl;
    
    int calcResult = moduleA->calculate(5, 3);
    std::cout << "Calculate Result: " << calcResult << std::endl;
    
    double computeResult = moduleB->compute(4.0);
    std::cout << "Calculate Result: " << computeResult << std::endl;
    
    // 清理
    FreeLibrary(moduleADll);
    FreeLibrary(moduleBDll);
    
    std::cout << "\n=== App Program Ends ===" << std::endl;
    //std::cout << "Enter to exit...";
    //std::cin.get();
    
    return 0;
}