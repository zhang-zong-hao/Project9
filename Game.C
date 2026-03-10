#include "Game.h"
#include <cstdlib>
#include <ctime>
#include "Grass.h"
#include "Rabbit.h"
#include "Wolf.h"
#include "Tiger.h"

Game::Game(int tNum, int wNum, int rNum) : tigerNum(tNum), wolfNum(wNum), rabbitNum(rNum) {
    gui.init();
    for(int i = 0; i < rabbitNum; i++){
        Item* rb = new Rabbit(this, rand()%25, rand()%80);
        items.push_back(rb);
    }
    for(int i = 0; i < wolfNum; i++){
        Item* wl = new Wolf(this, rand()%25, rand()%80);
        items.push_back(wl);
    }
    for(int i = 0; i < tigerNum; i++){
        Item* tg = new Tiger(this, rand()%25, rand()%80);
        items.push_back(tg);
    }

    for(int i = 0; i < 25; i++ ){
        for(int j = 0;j < 80;j++){
            grasses.push_back(new Grass(this, i, j));
        }
    }
    count = 0;
}

void Game::update() {
    gui.clear(); //clear everything on the screen

    count++;
    printMsg(25,1, "day: ");
    printMsg(25,6,to_string(count).c_str());

    int c = gui.get();
    if(c == 'd'){
        rabbitNum++;
        Item* rb = new Rabbit(this, rand()%25, rand()%80);
        items.push_back(rb);
    }
    if(c == 'a'){
        if(rand()%2 == 0){
            wolfNum++;
            Item* wl = new Wolf(this, rand()%25, rand()%80);
            items.push_back(wl);
        }
        else{
            tigerNum++;
            Item* tg = new Tiger(this, rand()%25, rand()%80);
            items.push_back(tg);
        }
    }
    if(c == 'q'){
        items.clear();
        for(size_t i = 0;i < grasses.size();i++){
            delete grasses[i];
        }
        grasses.clear();
        gui.end();
        exit(0);
    }

    updateItems(c, count);
    printMsg(26,1, "rabbit: ");
    printMsg(26,8,to_string(rabbitNum).c_str());
    printMsg(27,1, "wolf: ");
    printMsg(27,8,to_string(wolfNum).c_str());
    printMsg(28,1, "tiger: ");
    printMsg(28,8,to_string(tigerNum).c_str());

    gui.redraw(); //draw things
}

void Game::updateItems(int c, size_t count) {
    for(size_t i = 0;i < 25*80;i++){
        grasses[i]->update(c, count);
    }
    list<Item*>::iterator bi = items.begin();
    while (bi != items.end() ) {
        (*bi)->update(c, count);
        if((*bi)->is_out == 1){
            if (dynamic_cast<Rabbit*>(*bi)) {
                rabbitNum--;
            } else if (dynamic_cast<Wolf*>(*bi)) {
                wolfNum--;
            } else if (dynamic_cast<Tiger*>(*bi)) {
                tigerNum--;
            }
            delete *bi;
            bi = items.erase(bi);
            continue;
        }
        bi++;
    }

}

void Game::paintAt(size_t r, size_t c, char x) {
    gui.paintat(r, c, x);
}
void Game::printMsg(size_t r, size_t c, const char* s) {
    gui.printMsg(r, c, s);
}

