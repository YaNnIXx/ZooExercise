#pragma once

#include "section.h"

class Zoo {
public:
    void accept(Observer& observer)
    {
        observer.visit(*this);
    }
    std::vector<Section> sections_;
};