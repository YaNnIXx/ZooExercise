#pragma once

#include "animal.h"

class Tiger : public Animal {
public:
    void accept(Observer& observer) override
    {
        observer.visit(*this);
    }
    Tiger(std::string name, float weight)
        : Animal(name, weight, true, "Savannah")
    {
    }
};