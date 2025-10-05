#include "Person.h"
#include "IPet.h"
#include <iostream>

struct Person::Impl {
    std::string name;
    int age;
    Impl(const std::string& n, int a) : name(n), age(a) {}
    void greet() { std::cout << "Hello, I'm " << name << ", age " << age << std::endl; }
    void playWith(IPet* pet) { if(pet) pet->speak(); }
};

Person::Person(const std::string& name, int age) : pImpl(std::make_unique<Impl>(name, age)) {}
Person::~Person() = default;
void Person::greet() { pImpl->greet(); }
void Person::playWith(IPet* pet) { pImpl->playWith(pet); }

extern "C" __declspec(dllexport) IPerson* CreatePerson(const char* name, int age) {
    return new Person(name, age);
}
