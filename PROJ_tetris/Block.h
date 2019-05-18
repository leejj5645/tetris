#ifndef BLOCK_H
#define BLOCK_H
#include <ncurses.h>


class Block{

  public:
    WINDOW *boardWin;
    int board[22][22];

    int type;
    int rotate;
    int cntRow;
    int removeRow;
    int getScore;
    int gameOver;
    int line;
    int x;
    int y;
    int canGo;
    //첫번째  칸 과  색 깔  로  구 분
    Block();

    void setBoard(WINDOW *win_);

    virtual void removeBlock();

    virtual void rotateBlock();

    virtual void addBlock();

    virtual void moveRight();

    virtual void moveLeft();

    virtual void moveDown();

    virtual void moveBottom();

    virtual void markBoard();

    int checkGo();

    void removeLine();

    void checkLine();

    int setScore();

    int endCheck();
 };


#endif
