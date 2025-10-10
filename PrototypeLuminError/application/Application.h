#pragma once
#include <windows.h>
#include "ICommon.h"
#include "IApplication.h"
#include "ISDLCore.h"


namespace LEApplication{
    class Application : public IApplication{
    public:
        ~Application();
        void Run(std::string exampleName) override;
        void Greet() override {std::cout<<"Hi, application greet!"<<std::endl;}

        Application();
        void Shutdown();
        void LoadSDLCore();
    private:
        HMODULE hSdlcore;
        LESDL::ISDLCore *pSdlcore = NULL;
    };

    extern "C" void* CreateInstance();
    extern "C" void DestroyInstance(void *p);
}