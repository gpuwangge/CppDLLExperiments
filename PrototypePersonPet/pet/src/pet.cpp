#include "Pet.h"
#include "IPerson.h"

namespace animal{
    
    struct Pet::Impl {
        std::string name;
        human::IPerson* person_;

        ~Impl() {
            std::cout << "Pet's Impl destroyed: " << name << "\n";
        }

        void speak() { std::cout << name << " says woof!" << std::endl; }
        void playWith(human::IPerson* person) {
            std::cout << name << " is playing with a person." << std::endl;
            person->greet();
        }

        void setPerson(human::IPerson* person) {person_ = person;}
        void playWithPerson(){
            std::cout << name << " is playing with THE person." << std::endl;
            person_->greet();
        }
    };

    Pet::Pet(const std::string& n) : pImpl(new Impl{n}) {}
    Pet::~Pet() {std::cout<<"Call Pet's destructor"<<std::endl;}

    void Pet::speak() { pImpl->speak(); }
    void Pet::playWith(human::IPerson* person) { pImpl->playWith(person); }

    void Pet::setPerson(human::IPerson* person){ pImpl->setPerson(person);}
    void Pet::playWithPerson(){pImpl->playWithPerson();}

    extern "C" IPet* CreatePet(const char* name) {
        return new Pet(name);
    }

}