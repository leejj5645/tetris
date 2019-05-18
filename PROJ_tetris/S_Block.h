#ifndef S_BLOCK_H
#define S_BLOCK_H
#include <ncurses.h>
#include "Block.h"


class S_Block : public Block{

    int sx[4];
    int sy[4];
    int srotateCnt;

public:
    S_Block();

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
