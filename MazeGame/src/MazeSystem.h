
#ifndef MAZESYSTEM_H
#define MAZESYSTEM_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include "GraphNode.h"
#include "Path.h"
#include "Stair.h"
#include "Road.h"
#include "Wall.h"
#include "Obstacle.h"
#include "FinishLine.h"
#include <fstream>
using namespace std;

class MazeSystem{
private:
    static constexpr char WALL_SYMBOL = '-';
    static constexpr char ROAD_SYMBOL = '*';
    static constexpr char FINISH_SYMBOL = '$';
    unordered_map<char,Stair*> stairMap;
    GraphNode* startNode;
    bool foundfinishNode;
    
    //queue is used for breadth first search
    queue<GraphNode*> qGraph;

    //a 3D vector maze (height z, width y, length x)
    vector<vector<vector<Path*>>> mazeMap;

    //a set can contain position (height z, length x, width y) is used to record which path program has made
    set<vector<int>> recordMap;

    //a map that can show the shortest path positions (x,y) based on the given key maze level index
    unordered_map<int,vector<vector<int>>> shortPathPos;

    //return the step cost when go to the given position
    //if GraphNode is nullptr mean program not finding that short path
    //return -1 if unable to go to the given position
    int checkPath(int z,int x,int y,GraphNode* prev);

    //Use deep first search to see if the path given is the shortest path
    //delete node after finish checking
    bool isShortPath(GraphNode* node);

    //check if the given position is out of bound
    bool isOutOfBound(int z,int x,int y);

    //update the UI maze
    void updateUI();

    //save the path position to map
    void savePath(GraphNode* node);

    //create maze map from read text file
    void createMap(ifstream& input);

//    void createEmptyMaze();

    //get path from character, and given position
    Path* getPath(char c,int z,int x,int y);
public:
    //create a maze base on given txt file.
    MazeSystem(ifstream& input);
    //destructor of MazeSystem
    ~MazeSystem();

    //return the smallest step required to get to the finish line
    //return -1 if impossible to get to the finish line
    int findShortPath(int startZ,int startX,int startY);

    //return the step cost when go to the given position
    //return -1 if unable to go to the given position
    int checkPath(int z,int x,int y);

    unordered_map<int,vector<vector<int>>> getMapDirection();

    vector<vector<vector<Path*>>> getMazeMap();

    int getLength();
    
    int getWidth();

    int getHeight();

};

#endif // MAZESYSTEM_H
