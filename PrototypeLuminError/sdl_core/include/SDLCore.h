#pragma once
#include "ISDLCore.h"
#include "ICommon.h"
#include "IApplication.h"

namespace LESDL{
    struct SDLCore : public ISDLCore {
        ~SDLCore(){std::cout<<"Call SDLCore's destructor"<<std::endl;}
        void greet() override;
        void SetApplication(LEApplication::IApplication* pApplication) override;
        // void playWith(animal::IPet* pet) override;

        SDLCore() {}
        // void playWithPet() override;
    private:
        // std::string name_;
        // int age_;
        LEApplication::IApplication* pApplication_;
    };

    extern "C" void* CreateInstance();
    extern "C" void DestroyInstance(void *p);

}