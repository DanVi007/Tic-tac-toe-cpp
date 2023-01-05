#include <exception>
#include <iostream>
#include <stdexcept>
#include "InputReader.h"
#include "../core/Board.h"
#include "UI.h"

using namespace std;
Board *board;

void printGuideBoard(){
  int position =1; 
  for(int y = 0; y< Board::size;y++) {
    for(int x = 0; x <Board::size ;x++) {
      cout << position++ << ",";
    }
    cout << endl;
  }
  cout << endl;
}
void printBoard(){
  char** prettyBoard = board->getPrettyBoard();
  int position = 1;
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
  bool turn = true;
  int round = 0;
  int cord;
  int score = 0;
  do {
    try{
      printGuideBoard();
      printBoard();
      cout << (turn ? "P1's " : "P2's ") << "turn" << endl;
      cord = readInt("Type in cord: ", 1,9); 
      score = board->setPos(cord, turn);
      round++;
      turn = !turn;
    } catch(invalid_argument& e) {
      cout << "\n" << e.what() << "\n\n";
    } 
  } while(score == 0 && round < 9);

  printBoard();
  if(score == 0){
    cout << "DRAW!" << endl;
  } else {
    cout << (turn ? "P2 " : "P1 ") << "WIN!" << endl;
  }
}

void start() {
  pvp();

}
