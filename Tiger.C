#include "Tiger.h"
#include "Game.h"
#include "Rabbit.h"
#include "Wolf.h"

Tiger::Tiger() : Predator() {}
Tiger::Tiger(Game* g, int r, int c)
    : Predator(g, r, c) {}

void Tiger::print(){
    game->paintAt(row, col, 'T');
}

void Tiger::update(int c, size_t count) {
    last++;
    move();
    print();
    if(last == 4){
        is_out = 1;
    }
}


void Tiger::move(){
    bool foundRabbit = false;
    bool foundWolf = false;
    for (Item* item : game->getItems()) {
        Rabbit* rb = dynamic_cast<Rabbit*>(item);
        if (rb && !rb->is_out) {
            int dr = rb->row - row;
            int dc = rb->col - col;
            if (abs(dr) <= 3 && abs(dc) <= 3) {
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
        if(rand()%2 == 0){
            for (Item* item : game->getItems()) {
                Wolf* wl = dynamic_cast<Wolf*>(item);
                if (wl && !wl->is_out) {
                    int dr = wl->row - row;
                    int dc = wl->col - col;
                    if (abs(dr) <= 3 && abs(dc) <= 3) {
                        row == wl->row;
                        col == wl->col;
                        wl->is_out = 1; 
                        last = 0;
                        foundWolf = true;
                        break; 
                    }
                }
            }
        }
        if (!foundWolf) {
        row += rand() % 7 - 3;
        col += rand() % 7 - 3;
        if (row < 0) row = 0;
        if (row > 24) row = 24;
        if (col < 0) col = 0;
        if (col > 79) col = 79;
        }
    }
}
