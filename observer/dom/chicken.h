#pragma once

#include "animal.h"

class Chicken : public Animal {
public:
    void accept(Observer& observer) override
    {
        observer.visit(*this);
    }
    Chicken(std::string name, float weight)
        : Animal(name, weight, false, "Tundra")
    {
    }
};