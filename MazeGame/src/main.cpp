// CS 133, Group-4 Finale Project: MazeGame

#include <iostream>
#include <queue>
#include <fstream>
#include "MazeSystem.h"
#include "ScoreBoard.h"
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

void printMsg() {
    cout << "Welcome to the CS133 Maze Labyrinth." << endl;
    cout << "To begin input a txt file that will represent the layout of the maze system" << endl;
    cout << "and then a file which creates the connections between mazes. The provided " << endl;
    cout << "example files are \"test.txt\" for the creation of each maze and \"event.txt\"" << endl;
    cout << "to create the interconnections. To move the player, use the arrow keys on" << endl;
    cout << "your keyboard to traverse through a level and use the shift key to move" << endl;
    cout << "between levels when positioned above stairs. Notes: Stairs are currently " << endl;
    cout << "represented as yellow blocks. You may need to click on the GUI window at" << endl;
    cout << "least once for keyboard presses to register." << endl << endl;;
}

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

bool askPlayAgain() {
    string input;
    cout << "Would you like to play again? ";
    cin >> input;
    cout << endl;

    return (tolower(input[0]) == 'y');
}


int main() {
    printMsg();
        ifstream* inputMaze = getInputFile("create a maze");
        ifstream* inputEvent = getInputFile("create stair event");
        ScoreBoard sb;
        bool playAgain = true;
        string name= "";
        while(playAgain){
            cout<<"What is your nickname?";
            cin>>name;
            inputMaze->clear();
            inputMaze->seekg(0,ios_base::beg);
            inputEvent->clear();
            inputEvent->seekg(0,ios_base::beg);
            MazeSystem* model = new MazeSystem(*inputMaze,*inputEvent);
            MazeGui* gui = new MazeGui(model, &sb);
            playAgain = askPlayAgain();
            if(model->getUser()->getType() == finishPoint){
                sb.add(name,model->getCurStep());
            }
            delete model;
            delete gui;
        }
        inputEvent->close();
        inputMaze->close();
        delete inputMaze;
        delete inputEvent;
        return 0;
}
