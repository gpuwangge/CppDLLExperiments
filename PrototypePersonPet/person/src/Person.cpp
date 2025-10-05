#include "Person.h"
#include "../interface/IPet.h"

void Person::playWith(IPet* pet) {
    std::cout << name << " is playing with a pet." << std::endl;
    pet->speak();
}

extern "C" IPerson* CreatePerson(const char* name, int age) {
    return new Person(name, age); 
}
