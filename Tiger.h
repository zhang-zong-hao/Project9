#ifndef TIGER_H
#define TIGER_H
#include "Predator.h"
class Tiger:public Predator {
public:
    Tiger();
    Tiger(Game* g, int r, int c);
    ~Tiger() {};
    virtual void update(int, size_t);
    virtual void print();
    void move();
};
#endif