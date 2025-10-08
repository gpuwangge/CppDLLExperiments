#include "Framework.h"
#include <windows.h>
#include "IPlay1.h"
#include "IPlay2.h"

namespace framework{
    CApp::CApp(){}
    CApp::~CApp(){}

    void CApp::run(){
        std::cout<<"framework::run()"<<std::endl;

        HMODULE play1DLL = LoadLibraryA("play1.dll"); //Windows.h
        using CreatePlay1Func = framework::IPlay1*(*)();
        auto CreateIPlay1 =  (CreatePlay1Func)GetProcAddress(play1DLL, "CreateIPlay1");
        framework::IPlay1* play1 = CreateIPlay1();
        play1->run();
        delete play1;
        FreeLibrary(play1DLL);

        HMODULE play2DLL = LoadLibraryA("play2.dll"); //Windows.h
        using CreatePlay2Func = framework::IPlay2*(*)();
        auto CreateIPlay2 =  (CreatePlay2Func)GetProcAddress(play2DLL, "CreateIPlay2");
        framework::IPlay2* play2 = CreateIPlay2();
        play2->run();
        delete play2;
        FreeLibrary(play2DLL);
    }


    extern "C" IApp* CreateApp(){
        return new CApp();
    }

}

