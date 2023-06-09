
#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
#include "Path.h"
using namespace std;

/*
 * GraphNode is used for finding the short path in the maze
*/

class GraphNode{
private:
    //use for the obstacle path which take more step than normal path
    int waitTurn;
    vector<GraphNode*> vGraph;
public:
    vector<vector<Path*>>* mazeMap;
    int x;
    int y;
    bool isFinishNode;
    GraphNode(int x,int y,vector<vector<Path*>>* mazeMap);
    GraphNode(int x,int y,vector<vector<Path*>>* mazeMap,int waitTurn);
    GraphNode(int x,int y,vector<vector<Path*>>* mazeMap,vector<GraphNode*> vGraph);
    //check if this node is waiting. the waitTurn is subtract by 1 every time is called
    bool isWait();
    GraphNode* getLastNode();
    bool empty();
    void addNode(GraphNode* node);
    void removeLastNode();
};

#endif // GRAPHNODE_H
