#pragma once

#include "observer/observer.h"

using namespace std;
class Animal {
public:
    virtual void accept(Observer& observer) = 0;
    Animal(string name, double weight, bool wild, string habitat)
        : name(name)
        , weight(weight)
        , wild(wild)
        , habitat(habitat)
    {
    }
    string name;
    double weight;
    bool wild;
    string habitat;
};