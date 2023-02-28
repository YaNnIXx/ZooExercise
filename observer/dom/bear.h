#pragma once

#include "animal.h"

class Bear : public Animal {
public:
    void accept(Observer& observer) override
    {
        observer.visit(*this);
    }
    Bear(std::string name, float weight)
        : Animal(name, weight, true, "Forest")
    {
    }
};