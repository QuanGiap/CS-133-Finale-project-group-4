#include "LinkedNode.h"
LinkedNode::LinkedNode(int x,int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->prev = nullptr;
}
LinkedNode::LinkedNode(int x,int y, int z,LinkedNode* prev){
    this->x = x;
    this->y = y;
    this->z = z;
    this->prev = prev;
}

