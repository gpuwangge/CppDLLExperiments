#include "Person.h"
#include "IPet.h"
#include "ICommon.h"

struct Person::Impl {
    std::string name;
    int age;
    
    void greet() { std::cout << "Hello, I'm " << name << std::endl; }
    void playWith(IPet* pet) {
        std::cout << name << " is playing with a pet." << std::endl;
        pet->speak();
    }
};

Person::Person(const char* name, int age) : pImpl(new Impl{name, age}) {}
Person::~Person() { delete pImpl; }

void Person::greet() { pImpl->greet(); }
void Person::playWith(IPet* pet) { pImpl->playWith(pet); }

extern "C" IPerson* CreatePerson(const char* name, int age) {
    return new Person(name, age);
}
