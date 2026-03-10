#ifndef WOLF_H
#define WOLF_H
#include "Predator.h"
class Wolf:public Predator {
public:
    Wolf();
    Wolf(Game* g, int r, int c);
    ~Wolf() {};
    virtual void update(int, size_t);
    virtual void print();
    void move();
};
#endif