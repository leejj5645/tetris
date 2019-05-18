#ifndef BOARD_H
#define BOARD_H
#include "Pane.h"

class BoardPane : public Pane{
public:
  BoardPane(int x, int y, int w, int h);
  void draw();
};

#endif
