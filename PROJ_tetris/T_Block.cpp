#include "T_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    T_Block::T_Block(){
      tx[0] = 1;
      tx[1] = 2;
      tx[2] = 2;
      tx[3] = 2;
      ty[0] = 9;
      ty[1] = 9;
      ty[2] = 7;
      ty[3] = 11;

      canGo = 1;
      trotateCnt = 0;
    }


    void T_Block::rotateBlock(){

      if(trotateCnt == 0){
        this->removeBlock();
        tx[0]++;
        tx[2]++;
        tx[3]--;
        ty[0]-=2;
        ty[2]+=2;
        ty[3]-=2;
        trotateCnt = 1;
        this->addBlock();
      }

      else if(trotateCnt == 1 && ty[1] != 19){
        this->removeBlock();
        tx[0]++;
        tx[2]--;
        tx[3]++;
        ty[0]+=2;
        ty[2]+=2;
        ty[3]-=2;
        trotateCnt = 2;
        this->addBlock();
      }

      else if(trotateCnt == 2){
        this->removeBlock();
        tx[0]--;
        tx[2]--;
        tx[3]++;
        ty[0]+=2;
        ty[2]-=2;
        ty[3]+=2;
        trotateCnt = 3;
        this->addBlock();
      }

      else if(trotateCnt == 3 && ty[1] != 1){
        this->removeBlock();
        tx[0]--;
        tx[2]++;
        tx[3]--;
        ty[0]-=2;
        ty[2]-=2;
        ty[3]+=2;
        trotateCnt = 0;
        this->addBlock();
      }
    }

    //remove
    void T_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, tx[i], ty[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void T_Block::addBlock(){

      init_pair(17, COLOR_CYAN, COLOR_CYAN);
      wattron(boardWin, COLOR_PAIR(17));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, tx[i], ty[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(17));
    }


    //right
    void T_Block::moveRight(){
      if(board[tx[0]][ty[0]+2] == 0 && board[tx[1]][ty[1]+2] == 0 && board[tx[2]][ty[2]+2] == 0 && board[tx[3]][ty[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            ty[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void T_Block::moveLeft(){

      if(board[tx[0]][ty[0]-1] == 0 && board[tx[1]][ty[1]-1] == 0 && board[tx[2]][ty[2]-1] == 0 && board[tx[3]][ty[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            ty[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void T_Block::moveDown(){
      this->removeBlock();

      if(board[tx[0]+1][ty[0]] == 0 && board[tx[1]+1][ty[1]] == 0 && board[tx[2]+1][ty[2]] == 0 && board[tx[3]+1][ty[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            tx[i] +=1;
        }
        this->addBlock();
      }


      if(board[tx[0]+1][ty[0]] != 0 || board[tx[1]+1][ty[1]] != 0 || board[tx[2]+1][ty[2]] != 0 || board[tx[3]+1][ty[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void T_Block::moveBottom(){

      this->removeBlock();

      while(board[tx[0]+1][ty[0]] == 0 && board[tx[1]+1][ty[1]] == 0 && board[tx[2]+1][ty[2]] == 0 && board[tx[3]+1][ty[3]] == 0){
        for(int i = 0; i<4; i++){
            tx[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void T_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[tx[i]][ty[i]] = 6;
        board[tx[i]][ty[i]+1] = 6;
      }

      init_pair(17, COLOR_CYAN, COLOR_CYAN);
      wattron(boardWin, COLOR_PAIR(17));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, tx[i], ty[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(17));

    }
