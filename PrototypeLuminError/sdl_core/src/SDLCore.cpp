#include "SDLCore.h"

namespace LESDL{
    void SDLCore::greet() { std::cout << "Hello, I'm " << "SDLCore" << std::endl; }
    void SDLCore::SetApplication(LEApplication::IApplication* application){pApplication_ = application; pApplication_->Greet();}
    // void Person::playWith(animal::IPet* pet) { pImpl->playWith(pet); }

    // void Person::setPet(animal::IPet* pet){ pImpl->setPet(pet);}
    // void Person::playWithPet(){pImpl->playWithPet();}

    // extern "C" IPerson* CreatePerson(const char* name, int age) {
    //     return new Person(name, age);
    // }
    extern "C" void* CreateInstance(){ return new SDLCore(); };
    extern "C" void DestroyInstance(void *p){ if(p) delete static_cast<SDLCore*>(p); }

}
