#pragma once
#include "../interface/IPet.h"
#include <iostream>

struct Pet : public IPet {
    Pet(const std::string& n);
    ~Pet();

    void speak() override;
    void playWith(IPerson* person) override;

private:
    struct Impl;   // 前向声明
    Impl* pImpl;   // 指向实现的指针
};

extern "C" IPet* CreatePet(const char* name); //need this function so GetProcAddress() can get correct address
