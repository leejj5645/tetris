#include "Z_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    Z_Block::Z_Block(){
      zx[0] = 1;
      zx[1] = 2;
      zx[2] = 2;
      zx[3] = 3;
      zy[0] = 9;
      zy[1] = 9;
      zy[2] = 7;
      zy[3] = 7;

      canGo = 1;
      zrotateCnt = 1;
    }


    void Z_Block::rotateBlock(){

      if(zrotateCnt == 1 && zy[0] != 19){
        this->removeBlock();
        zx[0]++;
        zx[2]--;
        zx[3]-=2;
        zy[0]+=2;
        zy[2]+=2;
        zrotateCnt = 0;
        this->addBlock();
      }

      else if(zrotateCnt == 0){
        this->removeBlock();
        zx[0]--;
        zx[2]++;
        zx[3]+=2;
        zy[0]-=2;
        zy[2]-=2;
        zrotateCnt = 1;
        this->addBlock();
      }
    }

    //remove
    void Z_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, zx[i], zy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void Z_Block::addBlock(){

      init_pair(14, COLOR_RED, COLOR_RED);
      wattron(boardWin, COLOR_PAIR(14));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, zx[i], zy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(14));
    }


    //right
    void Z_Block::moveRight(){
      if(board[zx[0]][zy[0]+2] == 0 && board[zx[1]][zy[1]+2] == 0 && board[zx[2]][zy[2]+2] == 0 && board[zx[3]][zy[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            zy[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void Z_Block::moveLeft(){

      if(board[zx[0]][zy[0]-1] == 0 && board[zx[1]][zy[1]-1] == 0 && board[zx[2]][zy[2]-1] == 0 && board[zx[3]][zy[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            zy[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void Z_Block::moveDown(){
      this->removeBlock();

      if(board[zx[0]+1][zy[0]] == 0 && board[zx[1]+1][zy[1]] == 0 && board[zx[2]+1][zy[2]] == 0 && board[zx[3]+1][zy[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            zx[i] +=1;
        }
        this->addBlock();
      }


      if(board[zx[0]+1][zy[0]] != 0 || board[zx[1]+1][zy[1]] != 0 || board[zx[2]+1][zy[2]] != 0 || board[zx[3]+1][zy[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void Z_Block::moveBottom(){

      this->removeBlock();

      while(board[zx[0]+1][zy[0]] == 0 && board[zx[1]+1][zy[1]] == 0 && board[zx[2]+1][zy[2]] == 0 && board[zx[3]+1][zy[3]] == 0){
        for(int i = 0; i<4; i++){
            zx[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void Z_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[zx[i]][zy[i]] = 5;
        board[zx[i]][zy[i]+1] = 5;
      }

      init_pair(14, COLOR_RED, COLOR_RED);
      wattron(boardWin, COLOR_PAIR(14));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, zx[i], zy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(14));

    }
