#pragma once

#include "animal.h"
#include <vector>

class Section {
public:
    void accept(Observer& observer)
    {
        observer.visit(*this);
    }
    std::vector<Animal*> animals_;
};