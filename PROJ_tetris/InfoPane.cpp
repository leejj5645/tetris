#include "InfoPane.h"
#include "Pane.h"

InfoPane::InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h){}

void InfoPane::draw(){
init_pair(2, COLOR_GREEN, COLOR_BLACK);
wattron(win_, COLOR_PAIR(2));
for (int i=0; i<height_; i++)
mvwhline(win_, i, 0, ACS_CKBOARD, width_);
mvwprintw(win_, 0,0, "INFO PANE");
wattroff(win_, COLOR_PAIR(2));
wrefresh(win_);
}

void InfoPane::showUser(char *username){

for(int i = 0; i<8; i++){
  name[i] = username[i];
}

init_pair(2, COLOR_GREEN, COLOR_BLACK);
wattron(win_, COLOR_PAIR(2));
mvwprintw(win_, 1, 0, name);
wattroff(win_, COLOR_PAIR(2));
wrefresh(win_);

}


void InfoPane::showSeed(int seed){
  cnt = 0;
  colcnt = 9;

  if(seed == 0){
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(2));
    mvwprintw(win_, 1, 9, "0");
    wattroff(win_, COLOR_PAIR(2));
  }

  while(seed != 0){
    seedArr[cnt] = seed % 10 + '0';
    seed /= 10;
    cnt++;
  }

  for (int i = cnt-1; i >= 0; i--){
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(2));
    mvwaddch(win_, 1, colcnt++, seedArr[i]);
    wattroff(win_, COLOR_PAIR(2));
  }
  wrefresh(win_);
}
