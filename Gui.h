#ifndef GUI_H
#define GUI_H
#include <ncurses.h>

class Gui {
    size_t row;
    size_t col;
    WINDOW* win;
public:
    Gui ():row(20),col(50) {init();}
    ~Gui() {endwin();}
    void init();
    int get();
    void paintat(size_t, size_t, char);
    void printMsg(int row, int col, const char* prompt);
    void clear();
    void redraw();
    void end() {endwin();}
};
#endif