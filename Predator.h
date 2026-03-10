#ifndef PREDATOR_H
#define PREDATOR_H
#include "Animal.h"
class Predator:public Animal {
public:
    Predator();
    Predator(Game* g, int r, int c);
    virtual void update(int, size_t) = 0;
    virtual void print() = 0;
    ~Predator() {};
};
#endif