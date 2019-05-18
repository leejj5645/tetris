#ifndef TETRIS_H
#define TETRIS_H
#include <ncurses.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Pane.h"
#include "BoardPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "StatPane.h"
#include "InfoPane.h"
#include "Block.h"
#include "I_Block.h"
#include "S_Block.h"
#include "Z_Block.h"
#include "L_Block.h"
#include "J_Block.h"
#include "T_Block.h"
#include <time.h>
#include <cstdlib>

class Tetris {
  Pane *infoPane_, *helpPane_, *nextPane_;
  BoardPane *boardPane_;
  StatPane *statPane_;
  WINDOW *board;
  Block *b;
  int shape;
  int tetrisScore;
  char *name;
  char name2[8];
  int seed;
  
public:
Tetris();
~Tetris();

void play();
void inputPlay(char* filename);
void updateScreen();
void creatBoard(WINDOW *win_);
void creatBlock();
void setUser(char *username);
};

#endif
