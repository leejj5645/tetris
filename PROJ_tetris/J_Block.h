#ifndef J_BLOCK_H
#define J_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class J_Block : public Block{

    int jx[4];
    int jy[4];
    int jrotateCnt;

public:
    J_Block();

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
