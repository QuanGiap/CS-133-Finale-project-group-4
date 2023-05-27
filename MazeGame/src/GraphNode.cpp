
#include "GraphNode.h"

GraphNode::GraphNode(int x,int y,int z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->isFinishNode = false;
}
GraphNode::GraphNode(int x,int y,int z,vector<GraphNode*> vGraph){
    this->x = x;
    this->y = y;
    this->z = z;
    this->isFinishNode = false;
    this->vGraph = vGraph;
}
bool GraphNode::isWait(){
    if(this->waitTurn > 0){
        this->waitTurn--;
    }
    return this->waitTurn != 0;
}

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
