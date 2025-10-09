#include "ICase001.h"
#include "ICommon.h"

namespace LECase{
    struct Case001 : public ICase001 {
        void run() override{
            std::cout<<"Case001::run()"<<std::endl; 
        }
    };

    extern "C" ICase001* CreateICase001(){
        return new Case001();
    }
}