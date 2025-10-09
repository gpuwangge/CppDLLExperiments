#include "Application.h"

namespace LEApplication{
    Application::Application(){}
    Application::~Application(){
        std::cout<<"~Application()"<<std::endl;
        if (dll_person) {
            FreeLibrary(dll_person);
            dll_person = nullptr;
        }
        if (dll_pet) {
            FreeLibrary(dll_pet);
            dll_pet = nullptr;
        }
    }

    void Application::Shutdown(){
        std::cout<<"Application::Shutdown()"<<std::endl;
        if (p_person) {
            using DestroyInstanceFunc = void(*)(void*);
            auto DestroyInstance_Plugin =  (DestroyInstanceFunc)GetProcAddress(dll_person, "DestroyInstance");
            if(!DestroyInstance_Plugin) { 
                std::cerr << "GetProcAddress failed! (DestroyInstance_Plugin)" << std::endl;
                FreeLibrary(dll_person);
                return;
            }

            DestroyInstance_Plugin(p_person);
            p_person = nullptr;
        }
        if (p_pet) {
            using DestroyInstanceFunc = void(*)(void*);
            auto DestroyInstance_Plugin =  (DestroyInstanceFunc)GetProcAddress(dll_pet, "DestroyInstance");
            if(!DestroyInstance_Plugin) { 
                std::cerr << "GetProcAddress failed! (DestroyInstance_Plugin)" << std::endl;
                FreeLibrary(dll_pet);
                return;
            }

            DestroyInstance_Plugin(p_pet);
            p_pet = nullptr;
        }
    }

    void Application::Run(std::string caseName){
        //std::cout<<"Application::Run(): Case Name = "<<caseName_<<std::endl;

        std::string caseNameDLL = caseName + ".dll";
        HMODULE dll = LoadLibraryA(caseNameDLL.c_str()); //Windows.h
        if(!dll) { 
            std::cerr << "DLL load failed! Case Name = " << caseName << std::endl; //Windows.h
            return; 
        }

        using CreateInstanceFunc = void*(*)();
        auto CreateInstance_Case =  (CreateInstanceFunc)GetProcAddress(dll, "CreateInstance");
        if(!CreateInstance_Case) { 
            std::cerr << "GetProcAddress failed! (CreateInstance)" << std::endl;
            FreeLibrary(dll);
            return;
        }
        using DestroyInstanceFunc = void(*)(void*);
        auto DestroyInstance_Case =  (DestroyInstanceFunc)GetProcAddress(dll, "DestroyInstance");
        if(!DestroyInstance_Case) { 
            std::cerr << "GetProcAddress failed! (DestroyInstance)" << std::endl;
            FreeLibrary(dll);
            return;
        }

        void* p_void = CreateInstance_Case();
        LECase::ICase *p = static_cast<LECase::ICase*>(p_void);

        try {
            p->Update();
        } catch (const std::exception& e) {
            std::cerr << "Exception in DLL Update(): " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown exception in DLL Update()." << std::endl;
        }

        DestroyInstance_Case(p);
        FreeLibrary(dll);

        LoadPerson();
        LoadPet();
    }

    void Application::LoadPerson(){
        dll_person = LoadLibraryA("person.dll"); 
        if(!dll_person) { 
            std::cerr << "DLL load failed! Case Name = " << "person.dll" << std::endl; 
            return; 
        }

        using CreateInstanceFunc = void*(*)(const char*, int);
        auto CreateInstance_Plugin =  (CreateInstanceFunc)GetProcAddress(dll_person, "CreateInstance");
        if(!CreateInstance_Plugin) { 
            std::cerr << "GetProcAddress failed! (CreateInstance_Plugin)" << std::endl;
            FreeLibrary(dll_person);
            return;
        }
        
        p_person = static_cast<human::IPerson*>(CreateInstance_Plugin("Alice", 30));
        p_person->greet(); //test p_person

    }

    void Application::LoadPet(){
        dll_pet = LoadLibraryA("pet.dll"); 
        if(!dll_pet) { 
            std::cerr << "DLL load failed! Case Name = " << "pet.dll" << std::endl; 
            return; 
        }

        using CreateInstanceFunc = void*(*)(const char*);
        auto CreateInstance_Plugin =  (CreateInstanceFunc)GetProcAddress(dll_pet, "CreateInstance");
        if(!CreateInstance_Plugin) { 
            std::cerr << "GetProcAddress failed! (CreateInstance_Plugin)" << std::endl;
            FreeLibrary(dll_pet);
            return;
        }
        
        p_pet = static_cast<animal::IPet*>(CreateInstance_Plugin("Buddy"));
        p_pet->speak(); //test p_pet
    }

    // void Application::SetCaseName(std::string caseName){
    //     caseName_ = caseName;
    // }

    extern "C" void* CreateInstance(){ return new Application();}
    extern "C" void DestroyInstance(void *p){ 
        if(p) {
            static_cast<Application*>(p)->Shutdown();
            delete static_cast<Application*>(p);
        } 
    }

}

