#include <iostream>
#include <fstream>

using namespace std;

#define FULL_BLOCK "\u2588"
#define NONE "\033[0m"

int main(int argc, char* argv[]) {
  string junk;
  int width, height;
  string filename;

  if(argc < 2){
    cout << "Please input a filename." << endl;
    exit(1);
  }

  filename = argv[1];

  ifstream fin;
  fin.open(filename);
  if(!fin.is_open()){
    cout << "Couldn't open your file..." << endl;
    exit(2);
  } else {
    // get static variables
    fin >> junk >> width >> height >> junk;

    // get colors
    string image[height][width];
    for(int row = 0; row < height; row += 1) {
      for(int col = 0; col < width; col += 1) {
        string r, g, b;
        fin >> r >> g >> b;
        image[row][col] = string("\033[38;2;") + r + ";" + g + ";" + b + "m" + FULL_BLOCK;
      }
    }

    // print image
    for(int row = 0; row < height; row += 1) {
      for(int col = 0; col < width; col += 1) {
        // doubled up to be more square
        cout << image[row][col] << image[row][col];
      }
      cout << endl << NONE;
    }
  }
  fin.close();
  return 0;
}
