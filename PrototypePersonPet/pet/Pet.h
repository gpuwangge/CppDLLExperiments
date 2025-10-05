#pragma once
#include "IPet.h"
#include <memory>
#include <string>

class Pet : public IPet {
public:
    Pet(const std::string& name);
    ~Pet();

    void speak() override;
    void playWith(IPerson* person) override;

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

extern "C" __declspec(dllexport) IPet* CreatePet(const char* name);
