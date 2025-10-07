#pragma once
#include "IPerson.h"
#include "ICommon.h"

namespace human{

    struct Person : public IPerson {
        Person(const char* name, int age);
        ~Person();

        void greet() override;
        void playWith(animal::IPet* pet) override;

        void setPet(animal::IPet *pet) override;
        void playWithPet() override;
    private:
        struct Impl;   // 前向声明
        std::unique_ptr<Impl> pImpl;
    };
    //Note: 这里用Impl隔离了一层，用户只能调用Person的greet和playWith函数，Person再转发给Impl

    extern "C" IPerson* CreatePerson(const char* name, int age); //need this function so GetProcAddress() can get correct address
    //Note: 这是一个"工厂函数"，也叫"导出函数"，它是这个Person DLL唯一暴露给外面的函数。用户通过这个函数获得指针后，就可以调用其内部的成员函数了。

}