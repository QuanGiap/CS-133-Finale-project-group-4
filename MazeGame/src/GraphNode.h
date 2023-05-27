
#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
using namespace std;


class GraphNode{
private:
    int waitTurn;
    vector<GraphNode*> vGraph;
public:
    int x;
    int y;
    int z;
    bool isFinishNode;
    GraphNode(int x,int y,int z);
    GraphNode(int x,int y,int z,int waitTurn);
    GraphNode(int x,int y,int z,vector<GraphNode*> vGraph);
    bool isWait();
    GraphNode* getLastNode();
    bool empty();
    void addNode(GraphNode* node);
    void removeLastNode();
};

#endif // GRAPHNODE_H
