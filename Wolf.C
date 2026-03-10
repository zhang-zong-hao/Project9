#include "Wolf.h"
#include "Game.h"
#include "Rabbit.h"

Wolf::Wolf() : Predator() {}
Wolf::Wolf(Game* g, int r, int c)
    : Predator(g, r, c) {}

void Wolf::print(){
    game->paintAt(row, col, 'W');
}

void Wolf::update(int c, size_t count) {
    last++;
    move();
    print();
    if(last == 3){
        is_out = 1;
    }
}

void Wolf::move(){
    bool foundRabbit = false;
    for (Item* item : game->getItems()) {
        Rabbit* rb = dynamic_cast<Rabbit*>(item);
        if (rb && !rb->is_out) {
            int dr = rb->row - row;
            int dc = rb->col - col;
            if (abs(dr) <= 2 && abs(dc) <= 2) {
                row == rb->row;
                col == rb->col;
                rb->is_out = 1; 
                last = 0;
                foundRabbit = true;
                break; 
            }
        }
    }
    if (!foundRabbit) {
        row += rand() % 5 - 3;
        col += rand() % 5 - 3;
        if (row < 0) row = 0;
        if (row > 24) row = 24;
        if (col < 0) col = 0;
        if (col > 79) col = 79;
    }
}
