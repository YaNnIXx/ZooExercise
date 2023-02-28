#include "lib/json.h"
#include "observer/dom/tiger.h"
#include "observer/dom/bear.h"
#include "observer/dom/chicken.h"
#include "observer/dom/zoo.h"
#include "observer/jsonObserver.h"
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

nlohmann::json toJson(Zoo& zoo)
{
    JsonObserver observer;
    zoo.accept(observer);
    return observer.json;
}

int main()
{
    Zoo zoo; Section section, section_2;

    Tiger tiger("Zenya", 170); Bear bear("Mishka", 340);
    Chicken chicken("Elsa", 4.5); Chicken chicken2("Nancy", 3.9);

    section.animals_.push_back(&tiger);
    section.animals_.push_back(&bear);
    zoo.sections_.push_back(section);

    section_2.animals_.push_back(&chicken);
    section_2.animals_.push_back(&chicken2);
    zoo.sections_.push_back(section_2);

    cout << toJson(zoo).dump(4) << endl;
    return 0;
}