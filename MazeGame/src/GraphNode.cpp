#include "GraphNode.h"
#include <iostream>
using namespace std;

/*
 * GraphNode is used for finding the short path in the maze
*/

GraphNode::GraphNode(int x,int y,vector<vector<Path*>>* mazeMap){
    this->x = x;
    this->y = y;
    this->mazeMap = mazeMap;
    this->waitTurn = 0;
    this->isFinishNode = false;
}
GraphNode::GraphNode(int x,int y,vector<vector<Path*>>* mazeMap,int waitTurn){
    this->x = x;
    this->y = y;
    this->mazeMap = mazeMap;
    this->waitTurn = waitTurn;
    this->isFinishNode = false;
}
GraphNode::GraphNode(int x,int y,vector<vector<Path*>>* mazeMap,vector<GraphNode*> vGraph){
    this->x = x;
    this->y = y;
    this->mazeMap = mazeMap;
    this->isFinishNode = false;
    this->vGraph = vGraph;
}

//check if this node is waiting. the waitTurn is subtract by 1 every time is called
bool GraphNode::isWait(){
    if(this->waitTurn > 0){
        this->waitTurn--;
    }
    return this->waitTurn != 0;
}

//check if there is any neightbour node
bool GraphNode::empty(){
    return this->vGraph.size() == 0;
}

void GraphNode::addNode(GraphNode* node){
    this->vGraph.push_back(node);
}
GraphNode* GraphNode::getLastNode(){
    if(vGraph.size()==0) return nullptr;
    return this->vGraph[vGraph.size()-1];
}
void GraphNode::removeLastNode(){
    if(vGraph.size()!=0){
        this->vGraph.pop_back();
    }
}
