
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
    //const symbol char to create maze
    static constexpr char WALL_SYMBOL = '-';
    static constexpr char ROAD_SYMBOL = '*';
    static constexpr char FINISH_SYMBOL = '$';
    //stair map is used to change the link between the stair
    unordered_map<char,Stair*> stairMap;
    //the starting node use for finding the short path
    GraphNode* startNode;
    //use to check if found finish  node during find the short path
    bool foundfinishNode;
    //current position of the player
    int curX;
    int curY;
    vector<vector<Path*>>* curMazeMap;
    //count how many step have made
    int curStep;
    //the number of steps need to trigger the event
    int triggerStep;
    //queue is used for breadth first search
    queue<GraphNode*> qGraph;
    //queue is used for event stair switch
    queue<vector<vector<char>>> qEventStair;
//    //a 3D vector maze (height z, width y, length x)
//    vector<vector<vector<Path*>>> mazeMap;

    //each 2d maze map have it own set which position (length x, width y)
    //It is used to record which path program has made
    unordered_map<vector<vector<Path*>>*,set<vector<int>>> recordMap;

    //a map that can show the shortest path positions (x,y) based on the given key maze level index
    vector<vector<int>> shortPathPos;

    //return the step cost when go to the given position
    //if GraphNode is nullptr mean program not finding that short path
    //return -1 if unable to go to the given position
    int checkPath(vector<vector<Path*>>* mazeMap,int x,int y,GraphNode* prev);

    //Use deep first search to see if the path given is the shortest path
    //delete node after finish checking
    bool isShortPath(GraphNode* node);

    //check if the given position is out of bound
    bool isOutOfBound(vector<vector<Path*>>* mazeMap,int x,int y);

    //change position of player,
    //return true if player successfully move to the given position
    bool changePosition(vector<vector<Path*>>* mazeMap,int x,int y,bool isUseStair);

    //save the path position to map
    void savePath(GraphNode* node);

    //create maze map from read text file
    void createMap(ifstream& inputMaze);

    //create stair event
    void createEvent(ifstream& inputEvent);

    //changing the link between the stair
    void triggerEvent();

    //reset find short path
    void resetFind();

    //get path from character, and given position
    Path* getPath(char c,vector<vector<Path*>>* mazeMap, int x,int y);
public:

    //create a maze base on given txt file.
    MazeSystem(ifstream& inputMaze,ifstream& inputEvent);
    //destructor of MazeSystem
    ~MazeSystem();

    //get color of the path base on given x, y
    string getColor(int x, int y) const;
    //get type of the path base on given x,y
    pathType getType(int x, int y) const;
    //get path of user currently on
    Path* getUser();
    //get path base on given x,y
    Path* get(int x, int y) const;

    //return the smallest step required to get to the finish line
    //return -1 if impossible to get to the finish line
    int findShortPath(int startX,int startY);

    //return the step cost when go to the given position
    //return -1 if unable to go to the given position
    int checkPath(vector<vector<Path*>>* mazeMap,int x,int y);

    //return map that show shortest map for maze
    //return vectors of position {x, y}
    vector<vector<int>>& getMapDirection();

    //return length x of the maze map
    int getLength() const;
    
    //return width y of the maze map
    int getWidth() const;

    //return the total stairs of this maze
    int getTotalStairs() const;

    //return current position of x
    int getCurX() const;

    //return current position of y
    int getCurY() const;

    //return current position of z
    vector<vector<Path*>>* getCurMaze() const;

    //return current step player have make
    int getCurStep() const;

    //move the player to the left
    //return true if succesfully moved
    bool moveLeft();

    //move the player to the right
    //return true if succesfully moved
    bool moveRight();

    //move the player up
    //return true if succesfully moved
    bool moveUp();

    //move the player down
    //return true if succesfully moved
    bool moveDown();

    //move the player to the next stair
    //return true if succesfully moved
    bool useStair();
};

#endif // MAZESYSTEM_H
