#ifndef T_BLOCK_H
#define T_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class T_Block : public Block{

    int tx[4];
    int ty[4];
    int trotateCnt;

public:
    T_Block();

    void removeBlock();

    void rotateBlock();

    void addBlock();

    void moveRight();

    void moveLeft();

    void moveDown();

    void moveBottom();

    void markBoard();

    void removeLine();
 };



#endif
