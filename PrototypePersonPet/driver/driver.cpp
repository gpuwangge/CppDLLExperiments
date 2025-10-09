#include "IPerson.h"
#include "IPet.h"
#include "ICore.h"

//#include "../app_personPlay/PersonPlay.h"

//If migrate to Linux, #include<dlfcn.h>
//dlopen(), dlerror(), dlsym(), and suffix .so instead of .dll, void* indead of HMODULE
//Or olternative: Boost.DLL
#include <windows.h>

#include <iostream>



//extern framework::IApp* framework::createApp();

int main(int argc, char* argv[]) {
    // std::cout << "Number of args: " << argc << "\n";
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << "Arg " << i << ": " << argv[i] << "\n";
    // }

    //std::cout<<"main"<<std::endl;
    HMODULE frameworkDLL = LoadLibraryA("core.dll"); //Windows.h
    using CreateAppFunc = LECore::IApplication*(*)();
    auto CreateApp =  (CreateAppFunc)GetProcAddress(frameworkDLL, "CreateApp");
    LECore::IApplication* app = CreateApp();
    if(argc > 1) app->SetSampleName(argv[1]);
    app->Run();
    
    delete app;
    FreeLibrary(frameworkDLL);

    //CPersonPlay personPlay; 

    //framework::IApp* app = framework::createApp();


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
