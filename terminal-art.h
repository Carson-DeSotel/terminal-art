/** 
 * Terminal Art Header
 * @author: Carson DeSotel
 * @date: 2020-09-12
 */

using namespace std;

#define FULL_BLOCK "\u2588\u2588"
#define NONE "\033[0m"
#define MAX_WIDTH 64
#define MAX_HEIGHT 64

bool validate_arguments(int argc, char* argv[]) {
    string filename;
    
    if(argc < 2) {
    cout << "Please input a filename." << endl;
    return false;
  }

  filename = argv[1];
  int filename_len = filename.length();

  // check file extension
  if(filename.substr(filename_len - 4).compare(".ppm") != 0 && 
     filename.substr(filename_len - 4).compare(".PPM") != 0 ) {
       cout << "File is not a ppm file..." << endl;
       return false;
  }

  return true;
}

void print_ppm(string (*image)[MAX_WIDTH], int height, int width) {
    for(int row = 0; row < height; row += 1) {
      for(int col = 0; col < width; col += 1) {
        cout << image[row][col];
      }
      cout << endl;
    }
}