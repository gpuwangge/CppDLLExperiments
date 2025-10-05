#include "IPerson.h"
#include "IPet.h"

//If migrate to Linux, #include<dlfcn.h>
//dlopen(), dlerror(), dlsym(), and suffix .so instead of .dll, void* indead of HMODULE
//Or olternative: Boost.DLL
#include <windows.h>

#include <iostream>

int main() {
    HMODULE personDLL = LoadLibraryA("libperson.dll"); //Windows.h
    HMODULE petDLL = LoadLibraryA("libpet.dll"); //Windows.h
    if(!personDLL || !petDLL) { 
        std::cerr << "DLL load failed! Error code: " << GetLastError() << std::endl; //Windows.h
        return -1; 
    }

    using CreatePersonFunc = IPerson*(*)(const char*, int);
    using CreatePetFunc = IPet*(*)(const char*);

    auto CreatePerson = (CreatePersonFunc)GetProcAddress(personDLL, "CreatePerson"); //Windows.h
    auto CreatePet = (CreatePetFunc)GetProcAddress(petDLL, "CreatePet"); //Windows.h

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
    FreeLibrary(personDLL); //Windows.h
    FreeLibrary(petDLL); //Windows.h
    return 0;
}
