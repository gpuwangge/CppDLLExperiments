#include "IPerson.h"
#include "IPet.h"

//If migrate to Linux, #include<dlfcn.h>
//dlopen(), dlerror(), dlsym(), and suffix .so instead of .dll, void* indead of HMODULE
//Or olternative: Boost.DLL
#include <windows.h>

#include <iostream>

int main() {
    HMODULE personDLL = LoadLibraryA("person.dll"); //Windows.h
    HMODULE petDLL = LoadLibraryA("pet.dll"); //Windows.h
    if(!personDLL || !petDLL) { 
        std::cerr << "DLL load failed! Error code: " << GetLastError() << std::endl; //Windows.h
        return -1; 
    }

    using CreatePersonFunc = human::IPerson*(*)(const char*, int);
    using CreatePetFunc = animal::IPet*(*)(const char*);

    //Grab create functions from Dlls
    auto CreatePerson = (CreatePersonFunc)GetProcAddress(personDLL, "CreatePerson"); //Windows.h
    auto CreatePet = (CreatePetFunc)GetProcAddress(petDLL, "CreatePet"); //Windows.h

    if(!CreatePerson || !CreatePet) { 
        std::cerr << "GetProcAddress failed!" << std::endl; 
        return -1;
    }


    human::IPerson* person = CreatePerson("Alice", 30);
    animal::IPet* pet = CreatePet("Buddy");

    //person->greet();
    //pet->speak();

    person->playWith(pet);
    pet->playWith(person);

    person->setPet(pet);
    person->playWithPet();

    pet->setPerson(person);
    pet->playWithPerson();

    delete person;
    delete pet;
    FreeLibrary(personDLL); //Windows.h
    FreeLibrary(petDLL); //Windows.h
    return 0;
}
