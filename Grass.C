#include "Grass.h"
#include "Game.h"

Grass::Grass() : Item() {}
Grass::Grass(Game* g, int r, int c)
    : Item(g, r, c) {
        pose = 3;
        be_ate = 0;
    }

void Grass::print(){
    if(pose == 1){
        game->paintAt(row, col, '.');
    }
    if(pose == 2){
        game->paintAt(row, col, ':');
    }
    if(pose == 3){
        game->paintAt(row, col, '*');
    }
    else{
        return;
    }
}

void Grass::update(int c, size_t count) {
    if(be_ate == 1){
        pose = 0;
        be_ate = 0;
        print();
        return;
    }
    if(pose < 3){
        pose++;
    }
    print();
}

bool Grass::eatable(){
    if(pose == 3)
        return true;
    else
        return false;
}