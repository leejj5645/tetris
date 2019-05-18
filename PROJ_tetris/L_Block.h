#ifndef L_BLOCK_H
#define L_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class L_Block : public Block{

    int lx[4];
    int ly[4];
    int lrotateCnt;

public:
    L_Block();

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
