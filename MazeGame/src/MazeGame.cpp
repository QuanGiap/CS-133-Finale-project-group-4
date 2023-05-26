
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
                    delete recordMap[i][j][k];
                }
            }
        }
    }
}
MazeGame::MazeGame(string fileName){
    this->isShowPath = false;
    this->finishNode =nullptr;
    //write code here
}

int MazeGame::checkPath(int x,int y,int z,LinkedNode* prev){
    //check if position check is out of bound or the program already used this path
    if(z<0||z>=mazeMap.size()||x<0||x>=mazeMap[z].size()||y<0||y>=mazeMap[z][x].size()||recordMap[z][x][y]!=nullptr){
        return -1;
    }
    int costStep = mazeMap[z][x][y]->getCostStep();
    if(costStep != -1 && prev != nullptr){
        LinkedNode* node = new LinkedNode(x,y,z,costStep,prev);
        this->recordMap[z][x][y] = node;
        this->qPos.push({z,x,y});
        Path* curPath = mazeMap[z][x][y];
        const pathType curPathT = curPath->getType();
        if(curPathT == stair){
            int toZ = ((Stair*)curPath)->getToZ();
            int toX = ((Stair*)curPath)->getToX();
            int toY = ((Stair*)curPath)->getToY();
            LinkedNode* newLevelNode = new LinkedNode(toX,toY,toZ,costStep,node);
            this->recordMap[toZ][toX][toY] = newLevelNode;
            this->qPos.push({toZ,toX,toY});
        }else if(curPathT==finishPoint){
            this->finishNode = node;
        }
    }
    return costStep;
}
int MazeGame::findShortPath(int startX,int startY, int startZ){
    int current_step = 0;
    const int step_check = this->checkPath(startX,startY,startZ,nullptr);
    if(step_check == -1) throw string("Start position invalid");
    LinkedNode* startNode = new LinkedNode(x,y,z,step_check);
    this->recordMap[startZ][startX][startY] = startNode;
    this->qPos.push({startZ,startX,startY});
    while(!qPos.empty()&&this->finishNode!=nullptr){
        int size = qPos.size();
        for(int i = 0; i < size;i++){
            vector<int> curPos = qPos.front();
            qPos.pop();
            int z = curPos[0];
            int x = curPos[1];
            int y = curPos[2];
            LinkedNode* curNode = recordMap[z][x][y];
            if(curNode->isWait()){
                this->qPos.push({z,x,y});
            }else{
                this->checkPath(x+1,y,z,curNode);
                this->checkPath(x-1,y,z,curNode);
                this->checkPath(x,y+1,z,curNode);
                this->checkPath(x,y-1,z,curNode);
            }     
        }
        current_step++;
    }
    if(this->finishNode==nullptr){
        return -1;
    }
    // check shortest part for finish Node
    return current_step;
}

