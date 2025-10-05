#pragma once
#include "IPerson.h"
#include <memory>
#include <string>

class Person : public IPerson {
public:
    Person(const std::string& name, int age);
    ~Person();

    void greet() override;
    void playWith(IPet* pet) override;

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

extern "C" __declspec(dllexport) IPerson* CreatePerson(const char* name, int age);
