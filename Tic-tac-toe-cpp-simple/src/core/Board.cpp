#include "Board.h"

Board::Board()
{
  Board::cord = new Board::cordWrap();
}

Board::~Board()
{
  delete cord;
}

struct Board::cordWrap * Board::getCord()
{
  return Board::cord;
}

char **Board::getPrettyBoard()
{
  char **prettyBoard = new char*[size];
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
bool Board::setPos(const int xPosition, const int yPosition,
                   bool startPlayer)
{
  if (Board::cord->cord[xPosition][yPosition])
    return false;
  Board::cord->cord[xPosition][yPosition] = startPlayer ? firstPlayer : secondPlayer;
  return true;
}

