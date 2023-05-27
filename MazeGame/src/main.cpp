// CS 133, Group-4 Finale Project: MazeGame

#include <iostream>
#include <queue>
#include <fstream>
#include "MazeGame.h"
#include "console.h"
using namespace std;

void getInputFile(ifstream& input) {
    string filename;
    cout<< "File name to create a Maze? ";
    bool isFile = false;    
    while(!isFile) {
        getline(cin, filename);
        input.open(filename);
        if(input.good()) {
            isFile = true;
        } else {
            input.close();
            cout << "File not found. Try again: ";
        }
    }
}

int main() {
    ifstream input;
    getInputFile(input);
    MazeGame mazeGame(input);
    return 0;
}
