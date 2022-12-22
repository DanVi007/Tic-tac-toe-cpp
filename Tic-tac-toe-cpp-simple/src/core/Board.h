#ifndef __BOARD
#define __BOARD
struct cordWrap{};
class Board{
  
public:
  Board();
  
  ~Board();
  static const int size = 3;
  struct cordWrap {
    int cord[size][size] = { };
  };
  cordWrap * cord;
  const int firstPlayer = 1;
  const int secondPlayer = 2;
  const char firstPiece = 'X';
  const char secondPiece = 'O';
  struct cordWrap* getCord();
  char ** getPrettyBoard();
  bool setPos(const int xPosition, const int yPosition, bool startPlayer); 
};

#endif
