#include "Person.h"
#include "IPet.h"


struct Person::Impl {
    std::string name;
    int age;
    IPet* pet_;

    ~Impl() {
        std::cout << "Person's Impl destroyed: " << name << "\n";
    }
    
    void greet() { std::cout << "Hello, I'm " << name << std::endl; }
    void playWith(IPet* pet) {
        std::cout << name << " is playing with a pet." << std::endl;
        pet->speak();
    }

    void setPet(IPet* pet) {pet_ = pet;}
    void playWithPet(){
        std::cout << name << " is playing with THE pet." << std::endl;
        pet_->speak();
    }
};

Person::Person(const char* name, int age) : pImpl(new Impl{name, age}) {}
Person::~Person(){std::cout<<"Call Person's destructor"<<std::endl;}

void Person::greet() { pImpl->greet(); }
void Person::playWith(IPet* pet) { pImpl->playWith(pet); }

void Person::setPet(IPet* pet){ pImpl->setPet(pet);}
void Person::playWithPet(){pImpl->playWithPet();}

extern "C" IPerson* CreatePerson(const char* name, int age) {
    return new Person(name, age);
}
