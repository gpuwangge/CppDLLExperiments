#include "IPerson.h"
#include "IPet.h"
#include <windows.h>
#include <iostream>
#include <functional>

int main() {
    HMODULE personDLL = LoadLibraryA("libperson.dll");
    HMODULE petDLL = LoadLibraryA("libpet.dll");
    if(!personDLL || !petDLL) { 
        std::cerr << "DLL load failed! Error code: " << GetLastError() << std::endl; 
        return -1; 
    }

    using CreatePersonFunc = IPerson*(*)(const char*, int);
    using CreatePetFunc = IPet*(*)(const char*);

    auto CreatePerson = (CreatePersonFunc)GetProcAddress(personDLL, "CreatePerson");
    auto CreatePet = (CreatePetFunc)GetProcAddress(petDLL, "CreatePet");

    if(!CreatePerson || !CreatePet) { 
        std::cerr << "GetProcAddress failed!" << std::endl; 
        return -1; 
    }

    IPerson* p = CreatePerson("Alice", 30);
    IPet* pet = CreatePet("Buddy");

    p->greet();
    pet->speak();

    p->playWith(pet);
    pet->playWith(p);

    delete p;
    delete pet;
    FreeLibrary(personDLL);
    FreeLibrary(petDLL);
    return 0;
}
