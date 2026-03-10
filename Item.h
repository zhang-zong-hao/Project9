#ifndef ITEM_H
#define ITEM_H
#define MAXROW 30
#define MAXCOL 80
#include <iostream>
using namespace std;
class Game;
class Item {
public:
    int is_out;
    size_t row;
    size_t col;
    size_t last;
    Game* game;
    Item();
    virtual ~Item() {}
    Item(Game* g, int r, int c);
    virtual void update(int, size_t) = 0;
    virtual void print() = 0;
};
#endif