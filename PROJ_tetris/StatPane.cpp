#include "StatPane.h"
#include "Pane.h"

StatPane::StatPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void StatPane::draw(){

init_pair(6, COLOR_RED, COLOR_BLACK);
wattron(win_, COLOR_PAIR(6));
box(win_, 0, 0);
mvwprintw(win_, 0, 5, "STATISTICS");
mvwprintw(win_, 1, 5, "score:");
wattroff(win_, COLOR_PAIR(6));
wrefresh(win_);
}

void StatPane::showScore(int score){

  cnt = 0;
  colcnt = 13;

  if(score == 0){
    init_pair(6, COLOR_RED, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(6));
    mvwprintw(win_, 1, 13, "0");
    init_pair(6, COLOR_RED, COLOR_BLACK);
    wattroff(win_, COLOR_PAIR(6));
  }

  while(score != 0){
    outScore[cnt] = score % 10 + '0';
    score /= 10;
    cnt++;
  }

  for (int i = cnt-1; i >= 0; i--){
    init_pair(6, COLOR_RED, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(6));
    mvwaddch(win_, 1, colcnt++, outScore[i]);
    wattroff(win_, COLOR_PAIR(6));
  }
  wrefresh(win_);

}
