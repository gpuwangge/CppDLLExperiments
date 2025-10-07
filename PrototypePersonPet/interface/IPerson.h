#pragma once

namespace animal{
    struct IPet;
}

namespace human{

    struct IPerson {
        virtual ~IPerson() = default;
        virtual void greet() = 0; 
        virtual void playWith(animal::IPet* pet) = 0;

        virtual void setPet(animal::IPet *pet) = 0;
        virtual void playWithPet() = 0;
    };

}
