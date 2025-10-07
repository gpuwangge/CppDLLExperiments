#pragma once

struct IPerson;

struct IPet {
    virtual ~IPet() = default;
    virtual void speak() = 0;
    virtual void playWith(IPerson* person) = 0;
};
