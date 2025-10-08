
#include "play2.h"

namespace framework{
    Play2::Play2(){}
    Play2::~Play2(){}

    void Play2::run(){
        std::cout<<"Play2::run()"<<std::endl;
    }


    extern "C" IPlay2* CreateIPlay2(){
        return new Play2();
    }

}

