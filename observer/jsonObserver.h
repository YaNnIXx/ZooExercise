#pragma once

#include "dom/tiger.h"
#include "dom/zoo.h"
#include "lib/json.h"

class JsonObserver : public Observer {
public:
    nlohmann::json json;
    void visit(Zoo& zoo) override
    {
        nlohmann::json animalJson;
        for (auto& animal : zoo.sections_) {
            JsonObserver observer;
            animal.accept(observer);
            animalJson.push_back(observer.json);
        }
        json.emplace("Sections", animalJson);
        json.emplace("Zoo", "Twelve Month");
    }
    void visit(Section& section) override
    {
        nlohmann::json sectionJson;
        for (auto& section : section.animals_) {
            JsonObserver observer;
            section->accept(observer);
            sectionJson.push_back(observer.json);
        }
        json.emplace("Animals", sectionJson);
    }
    void visit(Tiger& tiger) override
    {
        json.emplace("Type", "Tiger");
        json.emplace("Name", tiger.name);
        json.emplace("Weight", tiger.weight);
        json.emplace("_IsWild(?)", tiger.wild);
        json.emplace("_NaturalHabitat", tiger.habitat);
    }
    void visit(Bear& bear) override
    {
        json.emplace("Type", "Bear");
        json.emplace("Name", bear.name);
        json.emplace("Weight", bear.weight);
        json.emplace("_IsWild(?)", bear.wild);
        json.emplace("_NaturalHabitat", bear.habitat);
    }
    void visit(Chicken& chicken) override
    {
        json.emplace("Type", "Chicken");
        json.emplace("Name", chicken.name);
        json.emplace("Weight", chicken.weight);
        json.emplace("_IsWild(?)", chicken.wild);
        json.emplace("_NaturalHabitat", chicken.habitat);
    }
};