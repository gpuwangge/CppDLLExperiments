#include "Pet.h"
#include "IPerson.h"
#include <iostream>

struct Pet::Impl {
    std::string name;
    Impl(const std::string& n) : name(n) {}
    void speak() { std::cout << name << " says: Woof!" << std::endl; }
    void playWith(IPerson* person) { if(person) person->greet(); }
};

Pet::Pet(const std::string& name) : pImpl(std::make_unique<Impl>(name)) {}
Pet::~Pet() = default;
void Pet::speak() { pImpl->speak(); }
void Pet::playWith(IPerson* person) { pImpl->playWith(person); }

extern "C" __declspec(dllexport) IPet* CreatePet(const char* name) {
    return new Pet(name);
}
