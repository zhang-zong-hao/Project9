#ifndef ANIMAL_H
#define ANIMAL_H
#include "Item.h"
#include <iostream>
using namespace std;

class Animal:public Item {
public:
    Animal();
    Animal(Game* g, int r, int c);
    virtual void update(int, size_t) = 0;
    virtual void print() = 0;
    ~Animal() {};
};

#endif