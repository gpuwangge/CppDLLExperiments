#pragma once
#include "ICommon.h"
#include "ICase.h"

namespace LEApplication{
    class IApplication {
    public:
        virtual ~IApplication() = default;
        //when ~function is set to virtual, a chain of functions in vtable will be called

        virtual void Run(std::string caseName = "case001") = 0; //virtual function create vtable; in runtime, will check the table to execute function(dynamic dispatch)
        //if derived instance call, will run derived instance's function

        //virtual void SetCaseName(std::string caseName) = 0;

        //Notes:
        //virtual 普通函数	当你显式调用它（比如 obj->foo()）	实现运行时多态（调用正确版本）
        //virtual 析构函数	当你 delete 对象时自动调用	确保完整析构链（先 Derived 后 Base）   
    };
}