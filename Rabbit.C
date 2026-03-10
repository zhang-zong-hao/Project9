#include "Rabbit.h"
#include "Game.h"
#include "Grass.h"

Rabbit::Rabbit() : Animal() {}
Rabbit::Rabbit(Game* g, int r, int c)
    : Animal(g, r, c) {}

void Rabbit::print(){
    game->paintAt(row, col, 'R');
}

void Rabbit::update(int c, size_t count) {
    move();
    last++;
    if(game->grasses[row*80 + col]->eatable()){
        game->grasses[row*80 + col]->be_ate = 1;
        last = 0;
        print();
        return;
    }
    print();
    if(last == 3){
          is_out = 1;
    }
}

void Rabbit::move(){
    row = row + rand()%3 - 1;
    if(row < 0) row = 0;
    if(row > 24) row = 24;
    col = col + rand()%3 - 1;
    if(col < 0) col = 0;
    if(col > 79) col = 79;
}