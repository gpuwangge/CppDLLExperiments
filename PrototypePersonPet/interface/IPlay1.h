#pragma once

namespace framework{
    class IPlay1 {
    public:
        virtual ~IPlay1() = default;
        virtual void run() = 0; 
    };
}