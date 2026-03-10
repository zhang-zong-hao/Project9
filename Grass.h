#ifndef GRASS_H
#define GRASS_H
#include "Item.h"
class Grass:public Item {
public:
    int pose;
    int be_ate;
    Grass();
    Grass(Game* g, int r, int c);
    ~Grass() {};
    virtual void update(int, size_t);
    virtual void print();
    bool eatable();
};
#endif