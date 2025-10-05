#include "Pet.h"
#include "../interface/IPerson.h"

void Pet::playWith(IPerson* person) {
    std::cout << name << " is playing with a person." << std::endl;
    person->greet();
}

extern "C" IPet* CreatePet(const char* name) {
    return new Pet(name);
}
