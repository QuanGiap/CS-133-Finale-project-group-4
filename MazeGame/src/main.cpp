// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

// This program lets the user play a maze game. The maze game consists of a web of smaller mazes 
// that change over time. The individual mazes are input to the program as text files and it is 
// assumed they are of a valid format. A maze constructing text file must start with the first two
// lines denoting the starting postition of the user x,y. The rest of the file must then have 2
// lines representing the length and width of the maze and then the maze must then be created.
// To create a valid maze the '*' character represents paths, or roads, the user can move along, 
// and the '-' character represents walls that the user cannot move onto. Upper case letters are 
// used to denote stairs in mazes which are used as connections between mazes. A valid file must
// have one '$'  character for the finish point of the entire game. Additionally, numbers on a 
// maze represent obstacles which requires more steps to move through. The user is then
// asked to input a file to govern how the maze changes during the game. A valid file
// must have the first line denote the number of steps before a switch in the interconnections
// occurs. The file must then have each line consist of two of the letters used in the maze file
// to connect the two stairs. After the intial setup '-' characters on a line represent 
// different interconnections that can be configured during the game. The stairs for this
// configuration must be linked in the same way. 

// A user can create their maze system and and let others play. After a run the players are 
// asked if they want to continue, if so the the nickname of the next player can be typed into the 
// system. Once a player reaches the endpoint their name and the amount of steps it took to 
// beat the maze is displayed on the next runs. If a player doesn't know where to go
// they can use a hint and show the shortest path to the end point. This hint
// only lasts for a few steps before the player is on cooldown. The shortest path
// is referenced to the position of the user when the hint button was pressed. 

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

// Prints out a message that describes to the user how to interact with the game
void printMsg() {
    cout << "Welcome to the CS133 Maze Labyrinth." << endl;
    cout << "To begin input a txt file that will represent the layout of the maze system" << endl;
    cout << "and then a file which creates the connections between mazes. The provided " << endl;
    cout << "example files are 'maze.txt' for the creation of each maze and 'event.txt'" << endl;
    cout << "to create the interconnections. To move the player, use the arrow keys on" << endl;
    cout << "your keyboard to traverse through a level and use the shift key to move" << endl;
    cout << "between levels when positioned above stairs. Notes: Stairs are currently " << endl;
    cout << "represented as yellow blocks. You may need to click on the GUI window at" << endl;
    cout << "least once for keyboard presses to register." << endl << endl;;
}

// Check is the file is a valid input file to read in from
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

// Ask the user if the want to play again. Returns true if the
// first letter is y for yes. 
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
        // The check to keep playing the game once one person has finished
        while(playAgain){
            cout<<"What is your nickname? ";
            cin>>name;
            // Reset the input stream pointer to load the same maze/event
            inputMaze->clear();
            inputMaze->seekg(0,ios_base::beg);
            inputEvent->clear();
            inputEvent->seekg(0,ios_base::beg);

            MazeSystem* model = new MazeSystem(*inputMaze,*inputEvent);
            MazeGui* gui = new MazeGui(model, &sb);
            playAgain = askPlayAgain();

            // Add to the scoreboard only if the user found the finish point
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
        exit(0);
        return 0;
}
