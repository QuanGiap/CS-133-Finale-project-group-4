#include "MazeGame.h"
using namespace std;

//return the step cost when go to the given position
//if GraphNode is nullptr mean program not finding that short path
//return -1 if unable to go to the given position
int MazeGame::checkPath(int z,int x,int y,GraphNode* prev){
    //check if position check is out of bound or the program already used this path
    if(isOutOfBound(z,x,y)||(prev!=nullptr && recordMap.count({z,x,y}))){
        return -1;
    }
//    cout<<x<<" "<<y<<endl;
    int costStep = mazeMap[z][y][x]->getCostStep();
    //if program is finding short path
    if(costStep != -1 && prev != nullptr){
        recordMap.insert({z,x,y});
        GraphNode* newNode = new GraphNode(x,y,z,costStep);
        prev->addNode(newNode);
        this->qGraph.push(newNode);
        Path* curPath = mazeMap[z][y][x];
        const pathType curPathT = curPath->getType();
        //if path is stair, add new node in new level maze
        if(curPathT == stair){
            int toZ = ((Stair*)curPath)->getNextZ();
            int toX = ((Stair*)curPath)->getNextX();
            int toY = ((Stair*)curPath)->getNextY();
            this->checkPath(toZ,toX,toY,newNode);
        }else if(curPathT==finishPoint){
            this->foundfinishNode= true;
            newNode->isFinishNode = true;
        }
    }
    return costStep;
}

//return the smallest step required to get to the finish line
//return -1 if impossible to get to the finish line
int MazeGame::findShortPath(int sZ,int sX,int sY){
    int current_step = 0;
    //check if the start position is valid
    const int step_check = this->checkPath(sZ,sX,sY,nullptr);
    if(step_check == -1){
        return -1;
    }
    //setting up breadth first search
    startNode = new GraphNode(sX,sY,sZ,step_check);
    this->qGraph.push(startNode);
    this->recordMap.insert({sZ,sX,sY});
    while(!this->qGraph.empty()&&!this->foundfinishNode){
        int size = this->qGraph.size();
        for(int i = 0; i < size;i++){
            GraphNode* curNode = this->qGraph.front();
            this->qGraph.pop();
            int z = curNode->z;
            int x = curNode->x;
            int y = curNode->y;
            if(curNode->isWait()){
                this->qGraph.push(curNode);
            }else{
                this->checkPath(z,x+1,y,curNode);
                this->checkPath(z,x-1,y,curNode);
                this->checkPath(z,x,y+1,curNode);
                this->checkPath(z,x,y-1,curNode);
            }
        }
        current_step++;
    }
    //save the short path in map and delete node
    this->isShortPath(startNode);

    if(!this->foundfinishNode){
        return -1;
    }

    return current_step;
}

//Use deep first search to see if the path given is the shortest path
//delete node after finish checking
bool MazeGame::isShortPath(GraphNode* node){
    bool foundPath = false;
    if(node != nullptr) {
        if(node->isFinishNode){
            savePath(node);
            foundPath = true;
        }

        while(!node->empty()){
            if(isShortPath(node->getLastNode())){
                savePath(node);
                foundPath = true;
            }
            node->removeLastNode();
        }
        delete node;
    }
    return foundPath;
}

//check if the given position is out of bound
bool MazeGame::isOutOfBound(int z,int x,int y){
    return (z<0||z>=mazeMap.size()||y<0||y>=mazeMap[z].size()||x<0||x>=mazeMap[z][y].size());
}

 //update the UI maze
void MazeGame::updateUI(){

}

//save the path position to map
void MazeGame::savePath(GraphNode* node){
    int x = node->x;
    int y = node->y;
    int z = node->z;
    cout<<z<<" "<<x<<" "<<y<<endl;
    this->shortPathPos[z].push_back({x,y});
}

void MazeGame::readFile(ifstream& input){
    string str;
    int heightZ = 0;
    getline(input,str);
    this->startZ = stoi(str);
    getline(input,str);
    this->startX = stoi(str);
    getline(input,str); 
    this->startY = stoi(str);
    cout<<"Z is "<<startZ<<" X is "<<startX<<" Y is "<<startY<<endl;
    while(getline(input,str)){
        char c;
        int lengthX = stoi(str);
        getline(input,str);
        int widthY = stoi(str);
        vector<vector<Path*>> lineY;
        for(int i = 0;i < widthY;i++){
            vector<Path*> lineX;
            for(int j = 0;j < lengthX;j++){
                input>>noskipws>>c;
                Path* newPath = this->getPath(c,heightZ,j,i);
                lineX.push_back(newPath);
            }
            input>>noskipws>>c;
            lineY.push_back(lineX);
        }
        this->mazeMap.push_back(lineY);
        heightZ++;
    }
//    cout<<mazeMap.size()<<" "<<mazeMap[0].size()<<" "<<mazeMap[0][0].size();
}

void MazeGame::createEmptyMaze(vector<vector<vector<Path*>>> maze) {
    vector<vector<vector<Path*>>> newMaze;

    for(int z = 0; z < height; z++) {
        vector<vector<Path*>> maze2D;
        for(int x = 0; x < length; x++) {
            vector<Path*> row;
            for(int y = 0; y < width; y++) {
                row.push_back(new Road());
            }
            maze2D.push_back(row);
        }
        newMaze.push_back(maze2D);
    }

    mazeMap = newMaze;
}

Path* MazeGame::getPath(char c,int z,int x,int y){
    Path* newPath = nullptr;
    switch (c)    {
    case WALL_SYMBOL:
        newPath = new Wall();
        break;
    case ROAD_SYMBOL:
        newPath = new Road();
        break;
    case FINISH_SYMBOL:
        newPath = new FinishLine();
        break;
    default:
        if(isalpha(toupper(c))){
            if(this->stairMap.count(toupper(c))){
                throw string("Duplicate stair exist");
            }else{
                newPath = new Stair(x,y,z);
                this->stairMap[c] = (Stair*) newPath;
            }
        }else if(isdigit(c)){
            newPath = new Obstacle(c-'0');
        }
        else{
            cout<<"Invalid symbol is "<<c<<endl;
            throw string("Invalid symbol");
        }
        break;
    }
    return newPath;
}
//create a maze base on given txt file.
MazeGame::MazeGame(ifstream& input){
    this->isShowPath = false;
    this->foundfinishNode = false;
    this->readFile(input);
    int small = this->findShortPath(this->startZ,this->startX,this->startY);
    cout<<"Shortest step: "<<small<<endl;
    cout<<"Done find shortest path maze"<<endl;

    //write code here
}

MazeGame::~MazeGame(){
    cout<<"deleteting"<<endl;
    //delete every path
    for(int i = 0; i < mazeMap.size();i++){
        for(int j = 0; j < mazeMap[i].size();j++){
            for(int k = 0; k < mazeMap[i][j].size();k++){
                delete mazeMap[i][j][k];
            }
        }
    }
    //delete GraphNode
//    isShortPath(startNode);
}

//function will calculate the minimum step first
//before allow user to play the game
void MazeGame::startGame(int z,int x,int y){
    //write code here
}

//
void MazeGame::showPath(){
    //write code here
}

