#include <iostream>
using namespace std;
const int MAXCHAR = 100; 

int readInt(const char* message, const int min, const int max) {
  char buffer[MAXCHAR] = "";

  int number = 0; 
  bool wrong = false;

  do{
    wrong = false;
    cout << message << endl;
    cin.getline(buffer,MAXCHAR);
    number = atoi(buffer);
    if(number == 0 && buffer[0] != '0'){
      wrong = true; 
      cout << "\nERROR: Not an integer\n\n";
    }
  } while (wrong || number < min || number > max);
  return number;
}
