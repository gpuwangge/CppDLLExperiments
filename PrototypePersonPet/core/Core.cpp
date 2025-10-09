#include "Core.h"
#include <windows.h>
#include "ICase001.h"
#include "ICase002.h"

namespace LECore{
    Application::Application(){}
    Application::~Application(){}

    void Application::Run(){
        std::cout<<"framework::run(): caseName = "<<caseName_<<std::endl;

        //TODO:不希望在工厂函数的签名里写具体接口类型 IPlay1*，而希望完全动态生成（类似 void*），然后在客户端通过类型转换再使用。 这种做法在插件 / DLL 系统里非常常见，核心思路是 工厂函数返回 void*，客户端自己 cast
        std::string sampleNameDLL = caseName_ + ".dll";
        HMODULE sampleDLL = LoadLibraryA(sampleNameDLL.c_str()); //Windows.h
        using CreateSampleFunc = LECase::ICase001*(*)();
        auto CreateIPlay1 =  (CreateSampleFunc)GetProcAddress(sampleDLL, "CreateICase001");
        LECase::ICase001* sample = CreateIPlay1();
        sample->run();
        delete sample;
        FreeLibrary(sampleDLL);

        // HMODULE play1DLL = LoadLibraryA("play1.dll"); //Windows.h
        // using CreatePlay1Func = framework::IPlay1*(*)();
        // auto CreateIPlay1 =  (CreatePlay1Func)GetProcAddress(play1DLL, "CreateIPlay1");
        // framework::IPlay1* play1 = CreateIPlay1();
        // play1->run();
        // delete play1;
        // FreeLibrary(play1DLL);

        // HMODULE play2DLL = LoadLibraryA("play2.dll"); //Windows.h
        // using CreatePlay2Func = framework::IPlay2*(*)();
        // auto CreateIPlay2 =  (CreatePlay2Func)GetProcAddress(play2DLL, "CreateIPlay2");
        // framework::IPlay2* play2 = CreateIPlay2();
        // play2->run();
        // delete play2;
        // FreeLibrary(play2DLL);
    }

    void Application::SetSampleName(std::string caseName){
        caseName_ = caseName;
    }

    extern "C" IApplication* CreateApp(){
        return new Application();
    }

}

