#include "Application.h"

namespace LEApplication{
    Application::Application(){}
    Application::~Application(){
        std::cout<<"~Application()"<<std::endl;
        if (hSdlcore) {
            FreeLibrary(hSdlcore);
            hSdlcore = nullptr;
        }
    }

    void Application::Shutdown(){
        std::cout<<"Application::Shutdown()"<<std::endl;
        if (pSdlcore) {
            using DestroyInstanceFunc = void(*)(void*);
            auto DestroyInstance_Plugin =  (DestroyInstanceFunc)GetProcAddress(hSdlcore, "DestroyInstance");
            if(!DestroyInstance_Plugin) { 
                std::cerr << "GetProcAddress failed! (DestroyInstance_Plugin)" << std::endl;
                FreeLibrary(hSdlcore);
                return;
            }

            DestroyInstance_Plugin(pSdlcore);
            pSdlcore = nullptr;
        }
    }

    void Application::Run(std::string exampleName){
        std::string exampleDLL = exampleName + ".dll";
        HMODULE dll = LoadLibraryA(exampleDLL.c_str()); //Windows.h
        if(!dll) { 
            std::cerr << "DLL load failed! Example Name = " << exampleName << std::endl; //Windows.h
            return; 
        }

        using CreateInstanceFunc = void*(*)();
        auto CreateInstance_example =  (CreateInstanceFunc)GetProcAddress(dll, "CreateInstance");
        if(!CreateInstance_example) { 
            std::cerr << "GetProcAddress failed! (CreateInstance)" << std::endl;
            FreeLibrary(dll);
            return;
        }
        using DestroyInstanceFunc = void(*)(void*);
        auto DestroyInstance_example =  (DestroyInstanceFunc)GetProcAddress(dll, "DestroyInstance");
        if(!DestroyInstance_example) { 
            std::cerr << "GetProcAddress failed! (DestroyInstance)" << std::endl;
            FreeLibrary(dll);
            return;
        }

        void* p_void = CreateInstance_example();
        LEExample::IExample *p = static_cast<LEExample::IExample*>(p_void);

        try {
            p->Update();
        } catch (const std::exception& e) {
            std::cerr << "Exception in DLL Update(): " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown exception in DLL Update()." << std::endl;
        }

        DestroyInstance_example(p);
        FreeLibrary(dll);

        LoadSDLCore();

        // p_person->playWith(p_pet);
        // p_person->setPet(p_pet);
        // p_person->playWithPet();

        // p_pet->playWith(p_person);
        // p_pet->setPerson(p_person);
        // p_pet->playWithPerson();
    }

    void Application::LoadSDLCore(){
        hSdlcore = LoadLibraryA("sdlcore.dll"); 
        if(!hSdlcore) { 
            std::cerr << "DLL load failed! Plugin Name = " << "sdlcore.dll" << std::endl; 
            return; 
        }

        using CreateInstanceFunc = void*(*)();
        auto CreateInstance_Plugin =  (CreateInstanceFunc)GetProcAddress(hSdlcore, "CreateInstance");
        if(!CreateInstance_Plugin) { 
            std::cerr << "GetProcAddress failed! (CreateInstance_Plugin)" << std::endl;
            FreeLibrary(hSdlcore);
            return;
        }
        
        pSdlcore = static_cast<LESDL::ISDLCore*>(CreateInstance_Plugin());
        pSdlcore->greet(); //test p_person
        pSdlcore->SetApplication(this);
    }

    extern "C" void* CreateInstance(){ return new Application();}
    extern "C" void DestroyInstance(void *p){ 
        if(p) {
            static_cast<Application*>(p)->Shutdown();
            delete static_cast<Application*>(p);
        } 
    }

}

