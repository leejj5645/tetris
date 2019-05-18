#ifndef PANE_H
#define PANE_H
#include "ncurses.h"
class Pane {
protected :
int width_, height_;
int x_, y_;
WINDOW *win_;
public:
Pane(int x, int y, int w, int h);
virtual ~Pane();

virtual void draw();

virtual void showUser(char *username);
virtual void showSeed(int seed);
};

#endif
