#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"
class Rabbit:public Animal {
public:
    Rabbit();
    Rabbit(Game* g, int r, int c);
    ~Rabbit() {};
    virtual void update(int, size_t);
    virtual void print();
    void move();
};
#endif