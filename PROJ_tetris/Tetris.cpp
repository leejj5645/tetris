#include "Tetris.h"
// #include <iostream>

Tetris::Tetris(){
initscr();
start_color();
cbreak();
refresh();

infoPane_ = new InfoPane(1,1,25,5);
helpPane_ = new HelpPane(1,6,25,12);
nextPane_ = new NextPane(1,18,25,5);
boardPane_ = new BoardPane(30,0,22,22);
statPane_ = new StatPane(60,3,20,20);
board = newwin(22,22,0,30);
}

Tetris::~Tetris(){
delete infoPane_;
delete helpPane_;
delete nextPane_;
delete boardPane_;
delete statPane_;
delete b;
delwin(board);
endwin();
}


void Tetris::play(){

curs_set(0);

keypad(stdscr,TRUE);
int key;
updateScreen();
srand(time(NULL));

infoPane_->showUser(name);


while(key != 'q'){

  tetrisScore = b->setScore();
  statPane_->showScore(tetrisScore);

  if(b->endCheck() == 0){
    break;
  }

key = getch();

switch(key){

  case KEY_UP:
    b->rotateBlock();
    break;

  case KEY_DOWN:
    b->moveDown();
    break;

  case KEY_RIGHT:
    b->moveRight();
    break;

  case KEY_LEFT:
    b->moveLeft();
    break;

  case ' ':
    b->moveBottom();
    break;

  default:
      break;
}

if(b->checkGo() == 0){
  delete b;
  creatBlock();
  do{
  b->checkLine();
  b->removeLine();
}while(b->removeRow != -1);
  b->addBlock();
}


}
}

void Tetris::updateScreen(){
infoPane_->draw();
helpPane_->draw();
nextPane_->draw();
boardPane_->draw();
statPane_->draw();
creatBoard(board);
creatBlock();
b->setBoard(board);
b->addBlock();
}



void Tetris::creatBoard(WINDOW *win_){
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
  wattron(win_, COLOR_PAIR(7));
  box(win_,0,0);
  wattroff(win_, COLOR_PAIR(7));
  wrefresh(win_);
}



void Tetris::creatBlock(){
  int shape = rand() % 7;
  if(shape == 6){
    b = new I_Block();
  }

  else if(shape == 0){
    b = new Block();
  }

  else if(shape == 3){
    b = new S_Block();
  }

  else if(shape == 4){
    b = new Z_Block();
  }

  else if(shape == 1){
    b = new L_Block();
  }

  else if(shape == 2){
    b = new J_Block();
  }

  else if(shape == 5){
    b = new T_Block();
  }


}

void Tetris::inputPlay(char *filename){

  std::ifstream inFile(filename);
  // updateScreen();
  char key;
  bool gameOver = false;

  updateScreen();

  inFile >> name2;
  infoPane_->showUser(name2);

  inFile >> seed;
  infoPane_->showSeed(seed);
  srand(seed);

  curs_set(0);

  while(!gameOver){


    tetrisScore = b->setScore();
    statPane_->showScore(tetrisScore);

    if(b->endCheck() == 0){
      break;
    }

    inFile >> key;

    switch(key){

    case 't':
      b->rotateBlock();
      break;

    case 'g':
      b->moveDown();
      break;

    case 'r':
      b->moveRight();
      break;

    case 'l':
      b->moveLeft();
      break;

    case 'd':
      b->moveBottom();
      break;

    case 'q':
      gameOver = true;
      break;

    default :
      break;

  }

  if(b->checkGo() == 0){
    delete b;
    creatBlock();
    do{
    b->checkLine();
    b->removeLine();
  }while(b->removeRow != -1);
    b->addBlock();
  }

  }

  getch();
}


void Tetris::setUser(char *username){
  name = username;
}
