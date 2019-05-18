#ifndef Z_BLOCK_H
#define Z_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class Z_Block : public Block{

    int zx[4];
    int zy[4];
    int zrotateCnt;

public:
    Z_Block();

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
