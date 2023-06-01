
#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
#include "Path.h"
using namespace std;


class GraphNode{
private:
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
    bool isWait();
    GraphNode* getLastNode();
    bool empty();
    void addNode(GraphNode* node);
    void removeLastNode();
};

#endif // GRAPHNODE_H
