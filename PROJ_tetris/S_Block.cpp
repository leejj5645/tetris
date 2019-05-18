#include "S_Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    S_Block::S_Block(){
      sx[0] = 1;
      sx[1] = 2;
      sx[2] = 2;
      sx[3] = 3;
      sy[0] = 9;
      sy[1] = 9;
      sy[2] = 11;
      sy[3] = 11;

      canGo = 1;
      srotateCnt = 1;
    }


    void S_Block::rotateBlock(){

      if(srotateCnt == 1 && sy[0] != 1){
        this->removeBlock();
        sx[0]++;
        sx[2]--;
        sx[3]-=2;
        sy[0]-=2;
        sy[2]-=2;
        srotateCnt = 0;
        this->addBlock();
      }

      else if(srotateCnt == 0){
        this->removeBlock();
        sx[0]--;
        sx[2]++;
        sx[3]+=2;
        sy[0]+=2;
        sy[2]+=2;
        srotateCnt = 1;
        this->addBlock();
      }
    }

    //remove
    void S_Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, sx[i], sy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void S_Block::addBlock(){

      init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA);
      wattron(boardWin, COLOR_PAIR(13));
      for(int i = 0; i<4; i++){
        mvwhline(boardWin, sx[i], sy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(13));
    }


    //right
    void S_Block::moveRight(){
      if(board[sx[0]][sy[0]+2] == 0 && board[sx[1]][sy[1]+2] == 0 && board[sx[2]][sy[2]+2] == 0 && board[sx[3]][sy[3]+2] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            sy[i] += 2;
        }
          this->addBlock();
      }
    }

    //left
    void S_Block::moveLeft(){

      if(board[sx[0]][sy[0]-1] == 0 && board[sx[1]][sy[1]-1] == 0 && board[sx[2]][sy[2]-1] == 0 && board[sx[3]][sy[3]-1] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            sy[i] -= 2;
        }
          this->addBlock();
      }

    }

    //down
    void S_Block::moveDown(){
      this->removeBlock();

      if(board[sx[0]+1][sy[0]] == 0 && board[sx[1]+1][sy[1]] == 0 && board[sx[2]+1][sy[2]] == 0 && board[sx[3]+1][sy[3]] == 0){
        this->removeBlock();
        for(int i = 0; i<4; i++){
            sx[i] +=1;
        }
        this->addBlock();
      }


      if(board[sx[0]+1][sy[0]] != 0 || board[sx[1]+1][sy[1]] != 0 || board[sx[2]+1][sy[2]] != 0 || board[sx[3]+1][sy[3]] != 0){
        markBoard();
        canGo = 0;
      }

    }


    void S_Block::moveBottom(){

      this->removeBlock();

      while(board[sx[0]+1][sy[0]] == 0 && board[sx[1]+1][sy[1]] == 0 && board[sx[2]+1][sy[2]] == 0 && board[sx[3]+1][sy[3]] == 0){
        for(int i = 0; i<4; i++){
            sx[i] +=1;
        }
      }

      this->addBlock();

      canGo = 0;
      markBoard();
    }

    void S_Block::markBoard(){

      for(int i = 0; i < 4; i++){
        board[sx[i]][sy[i]] = 4;
        board[sx[i]][sy[i]+1] = 4;
      }

      init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA);
      wattron(boardWin, COLOR_PAIR(13));
      for(int i = 0; i < 4; i++){
        mvwhline(boardWin, sx[i], sy[i], ACS_CKBOARD, 2);
      }
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(13));

    }
