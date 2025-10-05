#pragma once
#include "../interface/IPerson.h"
#include <iostream>

struct Person : public IPerson {
    Person(const char* name, int age);
    ~Person();

    void greet() override;
    void playWith(IPet* pet) override;
private:
    struct Impl;   // 前向声明
    Impl* pImpl;   // 指向实现的指针
};

extern "C" IPerson* CreatePerson(const char* name, int age); //need this function so GetProcAddress() can get correct address
//Note: 这是一个"工厂函数"，也叫"导出函数"，它是这个Person DLL唯一暴露给外面的函数。用户通过这个函数获得指针后，就可以调用其内部的成员函数了。