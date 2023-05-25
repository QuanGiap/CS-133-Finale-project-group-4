
#include "MazeGame.h"

MazeGame::~MazeGame(){
    //delete every path
    for(int i = 0; i < mazeMap.size();i++){
        for(int j = 0; j < mazeMap[i].size();j++){
            for(int k = 0; k < mazeMap[i][j].size();k++){
                delete mazeMap[i][j][k];
            }
        }
    }
    //delete LinkedNode
    for(int i = 0; i < recordMap.size();i++){
        for(int j = 0; j < recordMap[i].size();j++){
            for(int k = 0; k < recordMap[i][j].size();k++){
                if(recordMap[i][j][k] !=nullptr){
                    delete mazeMap[i][j][k];
                }
            }
        }
    }
}
MazeGame::MazeGame(string fileName){
    this->isShowPath = false;
}

int MazeGame::checkPath(int x,int y,int z,LinkedNode* prev){
    //check if position check is out of bound
    if(z<0||z>=mazeMap.size()||x<0||x>=mazeMap[z].size()||y<0||y>=mazeMap[z][x].size()){
        return -1;
    }
    int costStep = mazeMap[z][x][y]->getCostStep();
    if(costStep != -1 && prev != nullptr){
        if(prev->isWait()){
            this->qLNode.push(prev);
        }else{
            LinkedNode* node = new LinkedNode(x,y,z,costStep,prev);
            this->recordMap[x][y][z] = node;
            this->qLNode.push(node);
        }
    }
    return costStep;
}
int MazeGame::findShortPath(int x,int y, int z){
    this->checkPath(x,y,z,nullptr);
    return -1;
}

