/** 
 * Terminal Art 
 * @author: Carson DeSotel
 * @created: 2020-08-17
 */
#include <iostream>
#include <fstream>
#include "terminal-art.h"

using namespace std;

int main(int argc, char* argv[]) {
  string junk, fmt, filename;
  int height, width;

  if(!validate_arguments(argc, argv)) {
    exit(1);
  } else {
      filename = argv[1];
  }

  ifstream fin;
  fin.open(filename);
  if(!fin.is_open()){
    cout << "Couldn't open your file..." << endl;
    exit(2);
  } else {
    // check file format
    fin >> fmt;
    if(fmt.compare("P3") != 0) { 
      cout << "File is not a ppm P3 file..." << endl;
      exit(3);
    } else {
      // get static variables
      fin >> width >> height >> junk;
    }

    if(height > MAX_HEIGHT || width > MAX_WIDTH) {
      cout << "File is too large, will most likely result in Segmentation Fault..." << endl;
      exit(4);
    }

    // get colors
    string image[height][MAX_WIDTH];
    for(int row = 0; row < height; row += 1) {
      for(int col = 0; col < width; col += 1) {
        string r, g, b;
        fin >> r >> g >> b;
        string BG = string("\033[48;2;") + r + ";" + g + ";" + b + "m";
        string FG = string("\033[38;2;") + r + ";" + g + ";" + b + "m" + FULL_BLOCK;
        image[row][col] = BG + FG + NONE;
      }
    }

    print_ppm(image, height, width);
  }
  fin.close();
  return 0;
}
