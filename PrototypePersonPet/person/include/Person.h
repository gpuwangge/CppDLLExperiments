#pragma once
#include "../interface/IPerson.h"
#include <iostream>

struct Person : public IPerson {
    std::string name;
    int age;
    Person(const std::string& n, int a) : name(n), age(a) {}
    void greet() override { std::cout << "Hi, I am " << name << std::endl; }
    void playWith(IPet* pet) override; 
};

extern "C" IPerson* CreatePerson(const char* name, int age);
