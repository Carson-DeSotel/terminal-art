#include <iostream>

using namespace std;

int main() {
  // colors:
  string RED   = "\033[0;31m";
  string BLACK = "\033[0;030m";
  string WHITE = "\033[1;37m";
  string NONE  = "\033[0m";

  // characters:
  string full_block = "\u2588";
  string RB = RED + full_block;
  string BB = BLACK + full_block;
  string WB = WHITE + full_block;

  string pixels[][12] = {
    { " ", " ", " ", " ", BB, BB, BB, BB, " ", " ", " ", " "}, 
    { " ", " ", BB, BB, RB, RB, RB, RB, BB, BB, " ", " "},
    { " ", BB, RB, RB, RB, RB, RB, RB, RB, RB, BB, " "},  
    { " ", BB, RB, RB, RB, RB, RB, RB, RB, RB, BB, " "}, 
    { BB, RB, RB, RB, RB, RB, RB, RB, RB, RB, RB, BB },
    { BB, RB, RB, RB, RB, BB, BB, RB, RB, RB, RB, BB },
    { BB, BB, RB, RB, BB, WB, WB, BB, RB, RB, BB, BB },
    { BB, WB, BB, BB, BB, WB, WB, BB, BB, BB, WB, BB },
    { " ", BB, WB, WB, WB, BB, BB, WB, WB, WB, BB, " "},
    { " ", BB, WB, WB, WB, WB, WB, WB, WB, WB, BB, " "},
    { " ", " ", BB, BB, WB, WB, WB, WB, BB, BB, " ", " "},
    { " ", " ", " ", " ", BB, BB, BB, BB, " ", " ", " ", " "}, 
  };

  for(int i = 0; i < 12; i += 1) {
    for(int j = 0; j < 12; j += 1) {
      cout << pixels[i][j] << pixels[i][j];
    }
    cout << endl;
  }
}
