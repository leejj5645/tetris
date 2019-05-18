#include <ncurses.h>
#include "Tetris.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

   char username[8];
   curs_set(0);

   if(argc > 1){
     Tetris t;
      t.inputPlay(argv[1]);
   }

   else {
      cout << "테트리스 게임을 시작합니다." << endl;
      cout << "사용자의 이름을 입력하세요." << endl;
      cin >> username;

      Tetris t;
      t.setUser(username);
      t.play();
   }

   return 0;
}
