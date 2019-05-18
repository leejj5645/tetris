#include "L_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    L_Block::L_Block(){
      lx[0] = 1;
      lx[1] = 2;
      lx[2] = 3;
      lx[3] = 3;
      ly[0] = 9;
      ly[1] = 9;
      ly[2] = 9;
      ly[3] = 11;

      canGo = 1;
      lrotateCnt = 0;
    }


    void L_Block::rotateBlock(){

      if(lrotateCnt == 0 && ly[0] != 1){
        this->removeBlock();
        lx[0]++;
        lx[2]--;
        lx[3]-=2;
        ly[0]-=2;
        ly[2]+=2;
        lrotateCnt = 1;
        this->addBlock();
      }

      else if(lrotateCnt == 1){
        this->removeBlock();
        lx[0]++;
        lx[2]--;
        ly[0]+=2;
        ly[2]-=2;
        ly[3]-=4;
        lrotateCnt = 2;
        this->addBlock();
      }

      else if(lrotateCnt == 2 && ly[0] != 19){
        this->removeBlock();
        lx[0]--;
        lx[2]++;
        lx[3]+=2;
        ly[0]+=2;
        ly[2]-=2;
        lrotateCnt = 3;
        this->addBlock();
      }

      else if(lrotateCnt == 3){
        this->removeBlock();
        lx[0]--;
        lx[2]++;
        ly[0]-=2;
        ly[2]+=2;
        ly[3]+=4;
        lrotateCnt = 0;
        this->addBlock();
      }
    }

    //remove
    void L_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, lx[i], ly[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void L_Block::addBlock(){

      init_pair(15, COLOR_BLUE, COLOR_BLUE);
      wattron(boardWin, COLOR_PAIR(15));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, lx[i], ly[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(15));
    }


    //right
    void L_Block::moveRight(){
      if(board[lx[0]][ly[0]+2] == 0 && board[lx[1]][ly[1]+2] == 0 && board[lx[2]][ly[2]+2] == 0 && board[lx[3]][ly[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            ly[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void L_Block::moveLeft(){

      if(board[lx[0]][ly[0]-1] == 0 && board[lx[1]][ly[1]-1] == 0 && board[lx[2]][ly[2]-1] == 0 && board[lx[3]][ly[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            ly[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void L_Block::moveDown(){
      this->removeBlock();

      if(board[lx[0]+1][ly[0]] == 0 && board[lx[1]+1][ly[1]] == 0 && board[lx[2]+1][ly[2]] == 0 && board[lx[3]+1][ly[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            lx[i] +=1;
        }
        this->addBlock();
      }


      if(board[lx[0]+1][ly[0]] != 0 || board[lx[1]+1][ly[1]] != 0 || board[lx[2]+1][ly[2]] != 0 || board[lx[3]+1][ly[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void L_Block::moveBottom(){

      this->removeBlock();

      while(board[lx[0]+1][ly[0]] == 0 && board[lx[1]+1][ly[1]] == 0 && board[lx[2]+1][ly[2]] == 0 && board[lx[3]+1][ly[3]] == 0){
        for(int i = 0; i<4; i++){
            lx[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void L_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[lx[i]][ly[i]] = 2;
        board[lx[i]][ly[i]+1] = 2;
      }

      init_pair(15, COLOR_BLUE, COLOR_BLUE);
      wattron(boardWin, COLOR_PAIR(15));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, lx[i], ly[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(15));

    }
