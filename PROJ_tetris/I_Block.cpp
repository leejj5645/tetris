#include "I_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    I_Block::I_Block(){
      ix[0] = 1;
      ix[1] = 2;
      ix[2] = 3;
      ix[3] = 4;

      for(int i = 0; i<4; i++){
        iy[i] = 9;
      }

      canGo = 1;
      irotateCnt = 1;
    }


    void I_Block::rotateBlock(){

      if(irotateCnt == 1 && iy[3] < 17 && iy[0] != 1){
        this->removeBlock();
        ix[0]++;
        ix[2]--;
        ix[3]-=2;
        iy[0]-=2;
        iy[2]+=2;
        iy[3]+=4;
        irotateCnt = 0;
        this->addBlock();
      }

      else if(irotateCnt == 0){
        this->removeBlock();
        ix[0]--;
        ix[2]++;
        ix[3]+=2;
        iy[0]+=2;
        iy[2]-=2;
        iy[3]-=4;
        irotateCnt = 1;
        this->addBlock();
      }
    }

    //remove
    void I_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, ix[i], iy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void I_Block::addBlock(){

      init_pair(12, COLOR_WHITE, COLOR_WHITE);
      wattron(boardWin, COLOR_PAIR(12));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, ix[i], iy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(12));
    }


    //right
    void I_Block::moveRight(){
      if(board[ix[0]][iy[0]+2] == 0 && board[ix[1]][iy[1]+2] == 0 && board[ix[2]][iy[2]+2] == 0 && board[ix[3]][iy[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            iy[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void I_Block::moveLeft(){

      if(board[ix[0]][iy[0]-1] == 0 && board[ix[1]][iy[1]-1] == 0 && board[ix[2]][iy[2]-1] == 0 && board[ix[3]][iy[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            iy[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void I_Block::moveDown(){
      this->removeBlock();

      if(board[ix[0]+1][iy[0]] == 0 && board[ix[1]+1][iy[1]] == 0 && board[ix[2]+1][iy[2]] == 0 && board[ix[3]+1][iy[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            ix[i] +=1;
        }
        this->addBlock();
      }


      if(board[ix[0]+1][iy[0]] != 0 || board[ix[1]+1][iy[1]] != 0 || board[ix[2]+1][iy[2]] != 0 || board[ix[3]+1][iy[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void I_Block::moveBottom(){

      this->removeBlock();

      while(board[ix[0]+1][iy[0]] == 0 && board[ix[1]+1][iy[1]] == 0 && board[ix[2]+1][iy[2]] == 0 && board[ix[3]+1][iy[3]] == 0){
        for(int i = 0; i<4; i++){
            ix[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void I_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[ix[i]][iy[i]] = 7;
        board[ix[i]][iy[i]+1] = 7;
      }

      init_pair(12, COLOR_WHITE, COLOR_WHITE);
      wattron(boardWin, COLOR_PAIR(12));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, ix[i], iy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(12));

    }
