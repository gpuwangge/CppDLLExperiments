#pragma once

namespace framework{
    class IPlay2 {
    public:
        virtual ~IPlay2() = default;
        virtual void run() = 0;
    };
}