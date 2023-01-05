#include "Board.h"
#include <stdexcept>
#include <stdint.h>
#include <iostream>
using namespace std;

Board::Board()
{
  Board::cord = new Board::cordWrap();
}

Board::~Board()
{
  delete cord;
}

struct Board::cordWrap *Board::getCord()
{
  return Board::cord;
}

char **Board::getPrettyBoard()
{
  char **prettyBoard = new char *[size];
  for (int x = 0; x < size; x++)
  {
    prettyBoard[x] = new char[size];
    for (int y = 0; y < size; y++)
    {
      switch (Board::cord->cord[x][y])
      {
      case 0:
        prettyBoard[x][y] = ' ';
        break;
      case 1:
        prettyBoard[x][y] = firstPiece;
        break;
      case 2:
        prettyBoard[x][y] = secondPiece;
        break;
      default:
        prettyBoard[x][y] = 'E';
      }
    }
  }
  return prettyBoard;
}

/**
 * startPlayer: true for first player false for secondPlayer
 */
int Board::setPos(const int cord,
                   bool startPlayer)
{
  int xPosition = (cord -1) % size;
  int yPosition = (cord -1) / size;
  if (Board::cord->cord[xPosition][yPosition]){
    throw invalid_argument("Not an available position");
  }

  Board::cord->cord[xPosition][yPosition] = startPlayer ? firstPlayer : secondPlayer;
  return getResult(xPosition,yPosition);
}


int Board::getResult(const int xPosition, const int yPosition){
  int counter = 0;
  int sum;
  bool finished = false;
  do {
    sum = 0;
    int xValues[4] = {xPosition,0,0,2};
    int yValues[4] = {0,yPosition, 0,0};
    int x = xValues[counter];
    int y = yValues[counter];
    int xDirection = (counter == 3) ? -1 : 1;
    bool xStuck = (counter == 0) ? true : false; 
    bool yStuck = (counter == 1) ? true : false; 

    while(x < size && x >= 0 && y < size ){
      if(Board::cord->cord[x][y] == Board::firstPlayer) {
        sum++;
      } else if(Board::cord->cord[x][y] == Board::secondPlayer) {
        sum--;
      }

      if(!yStuck) {
        y++;
      }
      if(!xStuck){
        x += xDirection;
      }
    } 
    counter++;
  } while(sum != size && sum != -size && counter < 4);

  if(sum == size) {
    return INT16_MAX;
  } else if(sum == -size){
    return INT16_MIN;
  } 
  return 0;
}

