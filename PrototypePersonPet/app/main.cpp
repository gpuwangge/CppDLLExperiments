#include "IPerson.h"
#include "IPet.h"
#include <iostream>

extern "C" IPerson* CreatePerson(const char* name, int age);
extern "C" IPet* CreatePet(const char* name);

int main() {
    IPerson* p = CreatePerson("Alice", 30);
    IPet* pet = CreatePet("Buddy");

    p->greet();
    pet->speak();

    p->playWith(pet);
    pet->playWith(p);

    delete p;
    delete pet;
    return 0;
}
