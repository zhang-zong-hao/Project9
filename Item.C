#include "Item.h"
#include "Game.h"

Item::Item() : row (0), col (0), last(0), is_out(0) {}
Item::Item(Game* g, int r, int c) 
    : game(g), row (r), col (c), last(0), is_out(0) {}