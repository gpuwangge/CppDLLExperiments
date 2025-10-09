#include "ICommon.h"
#include "ICase001.h"

namespace LECase{
    struct Case001 : public ICase001 {
        void Update() override{
            std::cout<<"Case001::Update()"<<std::endl; 
        }
    };

    extern "C" void* CreateInstance(){ return new Case001();}
    extern "C" void DestroyInstance(void *p){ if(p) delete static_cast<Case001*>(p); }
}