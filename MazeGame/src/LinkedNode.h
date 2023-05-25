
#ifndef LINKEDNODE_H
#define LINKEDNODE_H




class LinkedNode{
public:
    int x;
    int y;
    int z;
    int waitTurn;
    LinkedNode* prev;
    LinkedNode(int x,int y, int z);
    LinkedNode(int x,int y, int z,LinkedNode* prev);
};

#endif // LINKEDNODE_H
