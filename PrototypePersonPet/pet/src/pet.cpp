#include "Pet.h"
#include "IPerson.h"

struct Pet::Impl {
    std::string name;

    ~Impl() {
        std::cout << "Pet's Impl destroyed: " << name << "\n";
    }

    void speak() { std::cout << name << " says woof!" << std::endl; }
    void playWith(IPerson* person) {
        std::cout << name << " is playing with a person." << std::endl;
        person->greet();
    }
};

Pet::Pet(const std::string& n) : pImpl(new Impl{n}) {}
Pet::~Pet() {std::cout<<"Call Pet's destructor"<<std::endl;}

void Pet::speak() { pImpl->speak(); }
void Pet::playWith(IPerson* person) { pImpl->playWith(person); }

extern "C" IPet* CreatePet(const char* name) {
    return new Pet(name);
}
