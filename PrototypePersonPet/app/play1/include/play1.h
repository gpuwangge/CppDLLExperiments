#pragma once
//#include "../../framework/include/Framework.h"
#include "IPlay1.h"
#include "ICommon.h"

namespace framework{
    struct Play1 : public IPlay1 {
        Play1();
        ~Play1();

        void run() override;
    };

    extern "C" IPlay1* CreateIPlay1();
}