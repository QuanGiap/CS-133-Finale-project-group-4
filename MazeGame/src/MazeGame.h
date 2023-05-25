
#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <vector>
#include "Path.h"
#include <iostream>
#include <unordered_map>
#include "LinkedNode.h"
#include <queue>

using namespace std;

class MazeGame{
private:
    bool isShowPath;
    //queue is used for breadth first search
    queue<LinkedNode*> qLNode;
    //a 3D vector maze (height, length, width)
    vector<vector<vector<Path*>>> mazeMap;
    //a 3D vector is used to record the step program has made
    vector<vector<vector<LinkedNode*>>> recordMap;
    unordered_map<int,vector<LinkedNode*>> mapLinked;
    //return the step cost when go to the given position
    //return -1 if unable to go to the given position
    int checkPath(int x,int y,int z,LinkedNode* prev);
    //return the smallest step required to get to the finish line
    //return -1 if impossible to get to the finish line
    int findShortPath(int x,int y,int z);
    //update the UI maze
    void updateUI();
public:
    //create a maze base on given txt file.
    MazeGame(string fileName);
    //destructor of MazeGame
    ~MazeGame();
    //function will calculate the minimum step first before allow user to play the game
    void startGame(int x,int y,int z);
    void showPath();
};

#endif // MAZEGAME_H
