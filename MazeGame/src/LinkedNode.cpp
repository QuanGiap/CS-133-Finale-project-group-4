#include "LinkedNode.h"
LinkedNode::LinkedNode(int x,int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->waitTurn = 0;
    this->prev = nullptr;
}

LinkedNode::LinkedNode(int x,int y, int z,int waitTurn){
    this->x = x;
    this->y = y;
    this->z = z;
    this->waitTurn = waitTurn;
    this->prev = nullptr;
}

LinkedNode::LinkedNode(int x,int y, int z,LinkedNode* prev){
    this->x = x;
    this->y = y;
    this->z = z;
    this->waitTurn = 0;
    this->prev = prev;
}

LinkedNode::LinkedNode(int x,int y, int z,int waitTurn, LinkedNode* prev){
    this->x = x;
    this->y = y;
    this->z = z;
    this->waitTurn = waitTurn;
    this->prev = prev;
}

bool LinkedNode::isWait(){
    if(this->waitTurn > 0){
        this->waitTurn--;
    }
    return this->waitTurn != 0;
}
