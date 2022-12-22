#include <iostream>
#include "InputReader.h"
#include "../core/Board.h"
#include "UI.h"

using namespace std;
Board *board;

void printBoard(){
  char** prettyBoard = board->getPrettyBoard();
  for(int y = 0; y< Board::size;y++) {
    for(int x = 0; x <Board::size ;x++) {
      cout << prettyBoard[x][y] << ",";
    }
    cout << endl;
  }
  cout << endl;
}

void pvp(){
  board = new Board();
  bool finished = false;
  bool turn = true;
  while(!finished){
    printBoard();
    int xPos;
    int yPos;
    do {
      cout << (turn ? "P1's " : "P2's ") << "turn" << endl;
      cout << "Type in cords " << endl;
      xPos = readInt("Type in xPos: ",1,3) -1 ;
      yPos = readInt("Type in yPos: ",1,3) -1 ;

    }while(!board->setPos(xPos,yPos,turn));
    turn = !turn; 
  }
  
}

void start() {
  pvp();

}
