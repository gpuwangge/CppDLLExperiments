#include "SDLCore.h"

namespace human{
    struct Person::Impl {
        std::string name;
        int age;
        //animal::IPet* pet_;

        ~Impl() {
            std::cout << "Person's Impl destroyed: " << name << "\n"; 
        }
        
        void greet() { std::cout << "Hello, I'm " << name << std::endl; }
    //     void playWith(animal::IPet* pet) {
    //         std::cout << name << " is playing with a pet." << std::endl;
    //         pet->speak();
    //     }

    //     void setPet(animal::IPet* pet) {pet_ = pet;}
    //     void playWithPet(){
    //         std::cout << name << " is playing with THE pet." << std::endl;
    //         pet_->speak();
    //     }
    };

    Person::Person(const char* name, int age) : pImpl(new Impl{name, age}) {}
    Person::~Person(){std::cout<<"Call Person's destructor"<<std::endl;}

    void Person::greet() { pImpl->greet(); }
    // void Person::playWith(animal::IPet* pet) { pImpl->playWith(pet); }

    // void Person::setPet(animal::IPet* pet){ pImpl->setPet(pet);}
    // void Person::playWithPet(){pImpl->playWithPet();}

    // extern "C" IPerson* CreatePerson(const char* name, int age) {
    //     return new Person(name, age);
    // }
    extern "C" void* CreateInstance(const char* name, int age){ return new Person(name, age); };
    extern "C" void DestroyInstance(void *p){ if(p) delete static_cast<Person*>(p); }

}
