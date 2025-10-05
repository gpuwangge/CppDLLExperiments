#pragma once
#include "../interface/IPet.h"
#include <iostream>

struct Pet : public IPet {
    std::string name;
    Pet(const std::string& n) : name(n) {}
    void speak() override { std::cout << name << " says: woof!" << std::endl; }
    void playWith(IPerson* person) override;
};

extern "C" IPet* CreatePet(const char* name);
