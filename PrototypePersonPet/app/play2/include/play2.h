#pragma once
//#include "../../framework/include/Framework.h"
#include "IPlay2.h"
#include "ICommon.h"

namespace framework{
    struct Play2 : public IPlay2 {
        Play2();
        ~Play2();

        void run() override;
    };

    extern "C" IPlay2* CreateIPlay2();
}