#pragma once

struct IPet;

struct IPerson {
    virtual ~IPerson() {}
    virtual void greet() = 0; 
    virtual void playWith(IPet* pet) = 0;
};
