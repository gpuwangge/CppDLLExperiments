#pragma once
#include "ICommon.h"

namespace LECase{
    class ICase{
    public:
        virtual ~ICase() = default;
        virtual void Update() = 0;
    };
}