#ifndef I_BLOCK_H
#define I_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class I_Block : public Block{

    int ix[4];
    int iy[4];
    int irotateCnt;

public:
    I_Block();

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
