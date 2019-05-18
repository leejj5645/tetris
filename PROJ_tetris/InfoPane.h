#ifndef INFO_H
#define INFO_H
#include "Pane.h"

class InfoPane : public Pane {

char name[8];
char seedArr[10];
int cnt;
int colcnt;
public:
InfoPane(int x, int y, int w, int h);
void draw();
void showUser(char *username);
void showSeed(int seed);
};

#endif
