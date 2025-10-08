#include "Framework.h"
#include <windows.h>
#include "IPlay1.h"
#include "IPlay2.h"

namespace framework{
    CApp::CApp(){}
    CApp::~CApp(){}

    void CApp::run(){
        std::cout<<"framework::run(): sampleName="<<sampleName_<<std::endl;

        //TODO:不希望在工厂函数的签名里写具体接口类型 IPlay1*，而希望完全动态生成（类似 void*），然后在客户端通过类型转换再使用。 这种做法在插件 / DLL 系统里非常常见，核心思路是 工厂函数返回 void*，客户端自己 cast
        std::string sampleNameDLL = sampleName_ + ".dll";
        HMODULE sampleDLL = LoadLibraryA(sampleNameDLL.c_str()); //Windows.h
        using CreateSampleFunc = framework::IPlay1*(*)();
        auto CreateIPlay1 =  (CreateSampleFunc)GetProcAddress(sampleDLL, "CreateIPlay1");
        framework::IPlay1* sample = CreateIPlay1();
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

    void CApp::setSampleName(std::string sampleName){
        sampleName_ = sampleName;
    }

    extern "C" IApp* CreateApp(){
        return new CApp();
    }

}

