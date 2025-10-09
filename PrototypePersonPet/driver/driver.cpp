#include "IPerson.h"
#include "IPet.h"
#include "IApplication.h"

//If migrate to Linux, #include<dlfcn.h>
//dlopen(), dlerror(), dlsym(), and suffix .so instead of .dll, void* indead of HMODULE
//Or olternative: Boost.DLL
#include <windows.h>

#include <iostream>


int main(int argc, char* argv[]) {
    // std::cout << "Number of args: " << argc << "\n";
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << "Arg " << i << ": " << argv[i] << "\n";
    // }


    HMODULE dll = LoadLibraryA("core.dll"); //Windows.h
    if(!dll) { 
        std::cerr << "DLL load failed! Core Name = core.dll" << std::endl; //Windows.h
        return -1; 
    }

    using CreateAppFunc = LEApplication::IApplication*(*)();
    auto CreateInstance =  (CreateAppFunc)GetProcAddress(dll, "CreateInstance");
    if(!CreateInstance) { 
        std::cerr << "GetProcAddress failed! (CreateInstance)" << std::endl;
        FreeLibrary(dll);
        return -1;
    }
    using DestroyAppFunc = void(*)(void*);
    auto DestroyInstance =  (DestroyAppFunc)GetProcAddress(dll, "DestroyInstance");
    if(!DestroyInstance) { 
        std::cerr << "GetProcAddress failed! (DestroyInstance)" << std::endl;
        FreeLibrary(dll);
        return -1;
    }

    LEApplication::IApplication* p = (LEApplication::IApplication*)CreateInstance();
    try {
        if(argc > 1) p->Run(argv[1]);
        else p->Run();
    } catch (const std::exception& e) {
        std::cerr << "Exception in Application::Run(): " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in Application::Run()" << std::endl;
    }
    
    DestroyInstance(p);
    FreeLibrary(dll);

    /*
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

    */

    return 0;
}
