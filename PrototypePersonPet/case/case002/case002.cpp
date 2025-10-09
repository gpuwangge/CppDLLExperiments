#include "ICommon.h"
#include "ICase002.h"

namespace LECase{
    struct Case002 : public ICase002 {
        void Update() override{
            std::cout<<"Case002::Update()"<<std::endl;
        }
    };

    extern "C" void* CreateInstance(){ return new Case002();}
    extern "C" void DestroyInstance(void *p){ if(p) delete static_cast<Case002*>(p); }
}