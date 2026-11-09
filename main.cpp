#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

double TYPE_ARRAY[4][9];

bool readColorChart();
void colorBlindness(int type, int red, int green, int blue, int& outR, int& outG, int& outB);
void selectType(char selectedType, int r, int g, int b, int& newR, int& newG, int& newB);

int main(){
    char selectedType;
    int r;
    int g;
    int b;
    int newR;
    int newG;
    int newB;
    bool stillRunning = true;

    if(!readColorChart()){
        return 1;
    }

    do{
        cout << "Please enter P for Protanopia, D for Deutranopia, T for Tritanopia, and A for Achromatopsia (Enter any other letter to exit the program):" << endl;
        cin >> selectedType;

        if(selectedType != 'P' && selectedType != 'D' &&  selectedType != 'T' && selectedType != 'A'){
            cout << "You have exited the program :(" << endl;
            stillRunning = false;
        }

        if(stillRunning){
            cout << "Please enter three numbers, for R, G, and B. (from 0-255, inclusive):" << endl;
            cin >> r >> g >> b;

            selectType(selectedType, r, g, b, newR, newG, newB);
        }

    }while(stillRunning);

    return 0;
}

bool readColorChart(){
    ifstream file("colorChart.txt");

    if(!file){
        cout << "Error opening colorChart.txt" << endl;
        return false;
    }

    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 9; col++){
            if(!(file >> TYPE_ARRAY[row][col])){
                cout << "Error reading colorChart.txt" << endl;
                return false;
            }
        }
    }

    file.close();
    return true;
}

void colorBlindness(int type, int red, int green, int blue, int& outR, int& outG, int& outB){
    outR = TYPE_ARRAY[type][0] * red + TYPE_ARRAY[type][1] * green + TYPE_ARRAY[type][2] * blue;
    outG = TYPE_ARRAY[type][3] * red + TYPE_ARRAY[type][4] * green + TYPE_ARRAY[type][5] * blue;
    outB = TYPE_ARRAY[type][6] * red + TYPE_ARRAY[type][7] * green + TYPE_ARRAY[type][8] * blue;

    outR = clamp(outR, 0, 255);
    outG = clamp(outG, 0, 255);
    outB = clamp(outB, 0, 255);
}

void selectType(char selectedType, int r, int g, int b, int& newR, int& newG, int& newB){
    if(selectedType == 'P'){
        colorBlindness(0, r, g, b, newR, newG, newB);
        cout << "Protanopia R G B: ";
    }
    else if(selectedType == 'D'){
        colorBlindness(1, r, g, b, newR, newG, newB);
        cout << "Deutranopia R G B: ";
    }
    else if(selectedType == 'T'){
        colorBlindness(2, r, g, b, newR, newG, newB);
        cout << "Tritanopia R G B: ";
    }
    else if(selectedType == 'A'){
        colorBlindness(3, r, g, b, newR, newG, newB);
        cout << "Achromatopsia R G B: ";
    }

    cout << newR << " " << newG << " " << newB << endl;
}
