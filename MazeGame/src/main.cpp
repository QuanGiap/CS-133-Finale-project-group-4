// CS 133, Group-4 Finale Project: MazeGame

#include <iostream>
#include <queue>
#include <fstream>
#include "MazeSystem.h"
#include "MazeGui.h"
#include "console.h"
using namespace std;

#define USING_QT

#ifdef USING_QT
const string PREFIX = "res/";
#include "console.h"
#else
const string PREFIX = "";
#endif

ifstream* getInputFile(string type) {
    ifstream* input = new ifstream();
    string filename;
    cout<< "File name to "+type+"? ";
    bool isFile = false;    
    while(!isFile) {
        getline(cin, filename);
        filename = PREFIX + filename;
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
    MazeSystem* model = new MazeSystem(*inputMaze,*inputEvent);
    MazeGui* gui = new MazeGui(model);
    delete inputMaze;
    delete inputEvent;
    return 0;
}
