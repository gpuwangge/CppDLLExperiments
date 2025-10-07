#pragma once

namespace human{
    struct IPerson;
}

namespace animal{
    struct IPet {
        virtual ~IPet() = default;
        virtual void speak() = 0;
        virtual void playWith(human::IPerson* person) = 0;

        virtual void setPerson(human::IPerson *person) = 0;
        virtual void playWithPerson() = 0;    
    };
}