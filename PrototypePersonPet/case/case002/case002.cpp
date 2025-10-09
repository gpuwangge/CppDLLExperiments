#include "ICase002.h"
#include "ICommon.h"

namespace LECase{
    struct Case002 : public ICase002 {
        void run() override{
            std::cout<<"Case002::run()"<<std::endl;
        }
    };

    extern "C" ICase002* CreateIPlay2(){
        return new Case002();
    }
}