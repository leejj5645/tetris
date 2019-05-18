#ifndef STAT_H
#define STAT_H
#include "Pane.h"
#include <stdlib.h>

class StatPane : public Pane {

char outScore[10];
int cnt;
int colcnt;
public:
StatPane(int x, int y, int w, int h);
void draw();
void showScore(int score);
};

#endif
