
#include "BoardPane.h"

BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void BoardPane::draw(){
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(7));
  box(win_, 0, 0);
  wattroff(win_, COLOR_PAIR(7));
  wrefresh(win_);
}
