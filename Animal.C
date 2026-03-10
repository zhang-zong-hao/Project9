#include "Animal.h"
#include "Game.h"

Animal::Animal() : Item() {}
Animal::Animal(Game* g, int r, int c)
    : Item(g, r, c) {}