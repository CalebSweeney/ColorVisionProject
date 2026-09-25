#include <iostream>
using namespace std;
#include <algorithm>

void protanopia(int red, int green, int blue, int& outR, int& outG, int& outB){
  outR = 0.567*red + 0.433*green;
  outG = 0.558*red + 0.442*green;
  outB = 0.242*green+ 0.758*blue;

  outR = clamp(outR, 0, 255);
  outG = clamp(outG, 0, 255);
  outB = clamp(outB, 0, 255);
}

void deutranopia(int red, int green, int blue, int& outR, int& outG, int& outB){
  outR = 0.625*red + 0.375*green;
  outG = 0.700*red + 0.300*green;
  outB = 0.300*green + 0.700*blue;

  outR = clamp(outR, 0, 255);
  outG = clamp(outG, 0, 255);
  outB = clamp(outB, 0, 255);
}

void tritanopia(int red, int green, int blue, int& outR, int& outG, int& outB){
  outR = 0.950*red + 0.050*green;
  outG = 0.433*green + 0.567*blue;
  outB = 0.475*green + 0.525*blue;

  outR = clamp(outR, 0, 255);
  outG = clamp(outG, 0, 255);
  outB = clamp(outB, 0, 255);
}

int main()
{
  char selectedType;
  int r;
  int g;
  int b;
  int newR = 0;
  int newG = 0;
  int newB = 0;

  cout << "Please enter R for Protanopia, G for Deutranopia, and B for Tritanopia:" << endl;
  cin >> selectedType;
  cout << "Please enter three numbers, for R, G, and B. (from 0-255, inclusive):" << endl;
  cin >> r >> g >> b;


  if(selectedType == 'R'){
    protanopia(r, g, b, newR, newG, newB);
    cout << "Protanopia R G B: " << newR << " " << newG << " " << newB << endl;
  }else if(selectedType == 'G'){
    deutranopia(r, g, b, newR, newG, newB);
    cout << "Deutranopia R G B: " << newR << " " << newG << " " << newB << endl;
  }else if(selectedType == 'B'){
    tritanopia(r, g, b, newR, newG, newB);
    cout << "Tritanopia R G B: " << newR << " " << newG << " " << newB << endl;
  }else{
    cout << selectedType << " is not a supported Color Blindness type, please try again." << endl;
  }


  return 0;
}
