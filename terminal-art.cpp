/** 
 * Terminal Art 
 * @author: Carson DeSotel
 * @created: 2020-08-17
 */
#include <iostream>
#include <fstream>

using namespace std;

#define FULL_BLOCK "\u2588\u2588"
#define NONE "\033[0m"

int main(int argc, char* argv[]) {
  string junk;
  string fmt;
  int width, height;
  string filename;

  if(argc < 2){
    cout << "Please input a filename." << endl;
    exit(1);
  }

  filename = argv[1];
  int filename_len = filename.length();

  // check file extension
  if(filename.substr(filename_len - 4).compare(".ppm") != 0 && 
     filename.substr(filename_len - 4).compare(".PPM") != 0 ) {
       cout << "File is not a ppm file..." << endl;
       exit(3);
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

    if(width > 64 || height > 64) {
      cout << "File is too large, will most likely result in Segmentation Fault..." << endl;
      exit(4);
    }

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
        cout << image[row][col];
      }
      cout << endl << NONE;
    }
  }
  fin.close();
  return 0;
}
