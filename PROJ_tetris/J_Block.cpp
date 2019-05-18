#include "J_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    J_Block::J_Block(){
      jx[0] = 1;
      jx[1] = 2;
      jx[2] = 3;
      jx[3] = 3;
      jy[0] = 9;
      jy[1] = 9;
      jy[2] = 9;
      jy[3] = 7;

      canGo = 1;
      jrotateCnt = 0;
    }


    void J_Block::rotateBlock(){

      if(jrotateCnt == 0 && jy[0] != 19){
        this->removeBlock();
        jx[0]++;
        jx[2]--;
        jy[0]-=2;
        jy[2]+=2;
        jy[3]+=4;
        jrotateCnt = 1;
        this->addBlock();
      }

      else if(jrotateCnt == 1){
        this->removeBlock();
        jx[0]++;
        jx[2]--;
        jx[3]-=2;
        jy[0]+=2;
        jy[2]-=2;
        jrotateCnt = 2;
        this->addBlock();
      }

      else if(jrotateCnt == 2 && jy[0] != 1){
        this->removeBlock();
        jx[0]--;
        jx[2]++;
        jy[0]+=2;
        jy[2]-=2;
        jy[3]-=4;
        jrotateCnt = 3;
        this->addBlock();
      }

      else if(jrotateCnt == 3){
        this->removeBlock();
        jx[0]--;
        jx[2]++;
        jx[3]+=2;
        jy[0]-=2;
        jy[2]+=2;
        jrotateCnt = 0;
        this->addBlock();
      }
    }

    //remove
    void J_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, jx[i], jy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void J_Block::addBlock(){

      init_pair(16, COLOR_GREEN, COLOR_GREEN);
      wattron(boardWin, COLOR_PAIR(16));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, jx[i], jy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(16));
    }


    //right
    void J_Block::moveRight(){
      if(board[jx[0]][jy[0]+2] == 0 && board[jx[1]][jy[1]+2] == 0 && board[jx[2]][jy[2]+2] == 0 && board[jx[3]][jy[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            jy[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void J_Block::moveLeft(){

      if(board[jx[0]][jy[0]-1] == 0 && board[jx[1]][jy[1]-1] == 0 && board[jx[2]][jy[2]-1] == 0 && board[jx[3]][jy[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            jy[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void J_Block::moveDown(){
      this->removeBlock();

      if(board[jx[0]+1][jy[0]] == 0 && board[jx[1]+1][jy[1]] == 0 && board[jx[2]+1][jy[2]] == 0 && board[jx[3]+1][jy[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            jx[i] +=1;
        }
        this->addBlock();
      }


      if(board[jx[0]+1][jy[0]] != 0 || board[jx[1]+1][jy[1]] != 0 || board[jx[2]+1][jy[2]] != 0 || board[jx[3]+1][jy[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void J_Block::moveBottom(){

      this->removeBlock();

      while(board[jx[0]+1][jy[0]] == 0 && board[jx[1]+1][jy[1]] == 0 && board[jx[2]+1][jy[2]] == 0 && board[jx[3]+1][jy[3]] == 0){
        for(int i = 0; i<4; i++){
            jx[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void J_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[jx[i]][jy[i]] = 3;
        board[jx[i]][jy[i]+1] = 3;
      }

      init_pair(16, COLOR_GREEN, COLOR_GREEN);
      wattron(boardWin, COLOR_PAIR(16));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, jx[i], jy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(16));

    }
