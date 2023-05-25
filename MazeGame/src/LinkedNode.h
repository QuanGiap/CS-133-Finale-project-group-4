
#ifndef LINKEDNODE_H
#define LINKEDNODE_H




class LinkedNode{
private:
    int waitTurn;
public:
    int x;
    int y;
    int z;
    LinkedNode* prev;
    LinkedNode(int x,int y, int z);
    LinkedNode(int x,int y, int z, int waitTurn);
    LinkedNode(int x,int y, int z,LinkedNode* prev);
    LinkedNode(int x,int y, int z,int waitTurn, LinkedNode* prev);
    bool isWait();
};

#endif // LINKEDNODE_H
