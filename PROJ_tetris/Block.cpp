#include "Block.h"


    //첫번째  칸 과  색 깔  로  구 분
    Block::Block(){
      x=1;
      y=9;
      canGo = 1;
    }

    void Block::setBoard(WINDOW *win_){
      boardWin = win_;

      //init
      for(int i = 0; i<=21; i++){
        for(int j = 0; j<=21; j++){
          board[i][j] = 0;
        }
      }

      //edge col
      for(int j = 0; j <=21; j++){
        board[0][j] = 1;
        board[21][j] = 1;
      }

      //edge row
      for(int i = 0; i <=21; i++){
        board[i][0] = 1;
        board[i][21] = 1;
      }

    }

    void Block::rotateBlock(){

    }

    //remove
    void Block::removeBlock(){
      init_pair(5, COLOR_BLACK, COLOR_BLACK);
      wattron(boardWin, COLOR_PAIR(5));
      mvwhline(boardWin, x, y, ACS_CKBOARD, 4);
      mvwhline(boardWin, x+1, y, ACS_CKBOARD, 4);
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(5));
    }

    //draw
    void Block::addBlock(){

      init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
      wattron(boardWin, COLOR_PAIR(8));
      mvwhline(boardWin, x, y, ACS_CKBOARD, 4);
      mvwhline(boardWin, x+1, y, ACS_CKBOARD, 4);

      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(8));
    }

    //right
    void Block::moveRight(){

      if(board[x][y+4] == 0 && board[x+1][y+4] == 0){
        this->removeBlock();
        y += 2;
      }

      this->addBlock();
    }

    //left
    void Block::moveLeft(){

      if(board[x][y-1] == 0 && board[x+1][y-1] == 0){
        this->removeBlock();
        y -= 2;
      }

      this->addBlock();
    }

    //down
    void Block::moveDown(){

      if((board[x+2][y] == 0) && (board[x+2][y+1]==0) && (board[x+2][y+2]==0) &&(board[x+2][y+3] == 0)){
          this->removeBlock();
          x+= 1;
          this->addBlock();
      }

      if((board[x+2][y] != 0) || (board[x+2][y+1] != 0) || (board[x+2][y+2] != 0) || (board[x+2][y+3] != 0)){
        markBoard();
        canGo = 0;
      }



    }


    void Block::moveBottom(){

      this->removeBlock();

      while((board[x+2][y] == 0) && (board[x+2][y+1]==0) && (board[x+2][y+2]==0) &&(board[x+2][y+3] == 0)){
        x+=1;
      }

      canGo = 0;
      markBoard();
    }

    void Block::markBoard(){

      for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
          board[x+i][y+j] = 1;
        }
      }

      init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
      wattron(boardWin, COLOR_PAIR(8));
      mvwhline(boardWin, x, y, ACS_CKBOARD, 4);
      mvwhline(boardWin, x+1, y, ACS_CKBOARD, 4);
      wrefresh(boardWin);
      wattroff(boardWin, COLOR_PAIR(8));

    }

    int Block::checkGo(){
      return canGo;
    }


    void Block::checkLine(){
      cntRow = 20;
      removeRow = -1;

      while(cntRow != 2){
        line = 1;
        for(int j = 1; j<21; j++){
          if(board[cntRow][j] == 0){
            line = 0;
          }
        }

        if(line == 1){
          removeRow = cntRow;
          getScore += 1;
          break;
        }

        else cntRow -= 1;
    }

    }



    void Block::removeLine(){

      if(removeRow != -1){
        for(int i = removeRow; i>=2; i--){
          for(int j = 1; j < 21; j++){
            board[i][j] = board[i-1][j];
          }
        }

        for(int i = 1; i<21; i++){
          for(int j = 1; j<21; j++){
            if(board[i][j] == 4){
              init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA);
              wattron(boardWin, COLOR_PAIR(13));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(13));
            }


            else if(board[i][j] == 7){
              init_pair(12, COLOR_WHITE, COLOR_WHITE);
              wattron(boardWin, COLOR_PAIR(12));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(12));
            }

            else if(board[i][j] == 1){
              init_pair(8, COLOR_YELLOW, COLOR_YELLOW);
              wattron(boardWin, COLOR_PAIR(8));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(8));
            }

            else if(board[i][j] == 0){
              init_pair(5, COLOR_BLACK, COLOR_BLACK);
              wattron(boardWin, COLOR_PAIR(5));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(5));
            }

            else if(board[i][j] == 5){
              init_pair(14, COLOR_RED, COLOR_RED);
              wattron(boardWin, COLOR_PAIR(14));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(14));
            }

            else if(board[i][j] == 2){
              init_pair(15, COLOR_BLUE, COLOR_BLUE);
              wattron(boardWin, COLOR_PAIR(15));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(15));
            }

            else if(board[i][j] == 3){
              init_pair(16, COLOR_GREEN, COLOR_GREEN);
              wattron(boardWin, COLOR_PAIR(16));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(16));
            }

            else if(board[i][j] == 6){
              init_pair(17, COLOR_CYAN, COLOR_CYAN);
              wattron(boardWin, COLOR_PAIR(17));
              mvwhline(boardWin, i, j, ACS_CKBOARD, 1);
              wrefresh(boardWin);
              wattroff(boardWin, COLOR_PAIR(17));
            }
          }
        }
      }

    }



    int Block::setScore(){
      return getScore;
    }

    int Block::endCheck(){
      gameOver = 1;

      for(int j = 1; j< 21; j++){
        if(board[1][j] != 0){
          gameOver = 0;
        }
      }
      return gameOver;
    }
