#ifndef GAME_H
#define GAME_H
#include <list>
#include <vector>
#include "Gui.h"
#include "Item.h"
using namespace std;

class Grass;
class Game {
    Gui gui;
    list <Item*> items;
    size_t count;
public:
    int rabbitNum = 0;
    int wolfNum = 0;
    int tigerNum = 0;
    vector <Grass*> grasses;
    Game(int tNum, int wNum, int rNum);
    ~Game() {gui.end();}
    void paintAt(size_t r, size_t c, char x);
    void printMsg(size_t r, size_t c, const char* s);
    void update();
    void updateItems(int c, size_t count);
    const list<Item*>& getItems() const { return items; }
};
#endif