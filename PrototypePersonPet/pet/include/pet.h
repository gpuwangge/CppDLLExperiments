#pragma once
#include "IPet.h"
#include "ICommon.h"

struct Pet : public IPet {
    Pet(const std::string& n);
    ~Pet();

    void speak() override;
    void playWith(IPerson* person) override;

private:
    struct Impl;   // 前向声明
    std::unique_ptr<Impl> pImpl;
};

extern "C" IPet* CreatePet(const char* name); //need this function so GetProcAddress() can get correct address
