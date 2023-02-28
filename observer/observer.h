#pragma once

class Zoo;
class Section;
class Tiger;
class Bear;
class Chicken;

class Observer {
public:
    virtual void visit(Zoo& zoo) = 0;
    virtual void visit(Section& section) = 0;
    virtual void visit(Tiger& tiger) = 0;
    virtual void visit(Bear& bear) = 0;
    virtual void visit(Chicken& chicken) = 0;
};