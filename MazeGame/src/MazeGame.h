
#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
//#include "LinkedNode.h"
#include "GraphNode.h"
#include "Path.h"
#include "Stair.h"
#include "Road.h"
#include "Wall.h"
#include "Obstacle.h"
#include "FinishLine.h"
using namespace std;

class MazeGame{
private:
    GraphNode* startNode;
    bool foundfinishNode;
    bool isShowPath;

    //queue is used for breadth first search
    queue<GraphNode*> qGraph;

    //a 3D vector maze (height z, length x, width y)
    vector<vector<vector<Path*>>> mazeMap;

    //a set can contain position (height z, length x, width y) is used to record which path program has made
    set<vector<int>> recordMap;

    //a map that can show the shortest path positions (x,y) based on the given key maze level index
    unordered_map<int,vector<vector<int>>> shortPathPos;

    //return the step cost when go to the given position
    //if GraphNode is nullptr mean program not finding that short path
    //return -1 if unable to go to the given position
    int checkPath(int z,int x,int y,GraphNode* prev);

    //return the smallest step required to get to the finish line
    //return -1 if impossible to get to the finish line
    int findShortPath(int startZ,int startX,int startY);

    //Use deep first search to see if the path given is the shortest path
    //delete node after finish checking
    bool isShortPath(GraphNode* node);

    //check if the given position is out of bound
    bool isOutOfBound(int z,int x,int y);

    //update the UI maze
    void updateUI();

    //save the path position to map
    void savePath(GraphNode* node);
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
