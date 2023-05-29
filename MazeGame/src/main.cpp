// CS 133, Group-4 Finale Project: MazeGame

#include <iostream>
#include <queue>
#include <fstream>
#include "MazeSystem.h"
#include "console.h"
using namespace std;

ifstream* getInputFile(string type) {
    ifstream* input = new ifstream();
    string filename;
    cout<< "File name to "+type+"? ";
    bool isFile = false;    
    while(!isFile) {
        getline(cin, filename);
        input->open(filename);
        if(input->good()) {
            isFile = true;
        } else {
            input->close();
            cout << "File not found. Try again: ";
        }
    }
    return input;
}

int main() {
    ifstream* inputMaze = getInputFile("create a maze");
    ifstream* inputEvent = getInputFile("create stair event");
    MazeSystem MazeSystem(*inputMaze,*inputEvent);
    delete inputMaze;
    delete inputEvent;
    return 0;
}
