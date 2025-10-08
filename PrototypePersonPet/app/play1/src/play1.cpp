
#include "play1.h"

namespace framework{
    Play1::Play1(){}
    Play1::~Play1(){}

    void Play1::run(){
        std::cout<<"Play1::run()"<<std::endl; 
    }


    extern "C" IPlay1* CreateIPlay1(){
        return new Play1();
    }

}

