#include "MazeSystem.h"
using namespace std;
//return the step cost when go to the given position
//if GraphNode is nullptr mean program not finding that short path
//return -1 if unable to go to the given position
int MazeSystem::checkPath(vector<vector<Path*>>* mazeMap,int x,int y,GraphNode* prev){
    //check if position check is out of bound or the program already used this path
    if(isOutOfBound(mazeMap,x,y)||(prev!=nullptr && recordMap[mazeMap].count({x,y}))){
        return -1;
    }
    int costStep = (*mazeMap)[y][x]->getCostStep();
    //if program is finding short path
    if(costStep != -1 && prev != nullptr){
        recordMap[mazeMap].insert({x,y});
        GraphNode* newNode = new GraphNode(x,y,mazeMap,costStep);
        prev->addNode(newNode);
        this->qGraph.push(newNode);
        Path* curPath = (*mazeMap)[y][x];
        const pathType curPathT = curPath->getType();
        //if path is stair, add new node in new level maze
        if(curPathT == stair){
            vector<vector<Path*>>* toMaze = ((Stair*)curPath)->getNextMaze();
            int toX = ((Stair*)curPath)->getNextX();
            int toY = ((Stair*)curPath)->getNextY();
            this->checkPath(toMaze,toX,toY,newNode);
        }else if(curPathT==finishPoint){
            this->foundfinishNode= true;
            newNode->isFinishNode = true;
        }
    }
    return costStep;
}

//return the smallest step required to get to the finish line
//return -1 if impossible to get to the finish line
int MazeSystem::findShortPath(int sX,int sY){
    int currentStep = 0;
    this->resetFind();
    //check if the start position is valid
    const int stepCheck = this->checkPath(this->curMazeMap,sX,sY);
    if(stepCheck == -1){
        return -1;
    }
    //setting up breadth first search
    startNode = new GraphNode(sX,sY,this->curMazeMap,stepCheck);
    this->checkPath(this->curMazeMap,sX,sY,startNode);
    while(!this->qGraph.empty()&&!this->foundfinishNode){
        int size = this->qGraph.size();
        for(int i = 0; i < size;i++){
            GraphNode* curNode = this->qGraph.front();
            this->qGraph.pop();
            vector<vector<Path*>>* mazeMap = curNode->mazeMap;
            int x = curNode->x;
            int y = curNode->y;
            if(curNode->isWait()){
                this->qGraph.push(curNode);
            }else{
                this->checkPath(mazeMap,x+1,y,curNode);
                this->checkPath(mazeMap,x-1,y,curNode);
                this->checkPath(mazeMap,x,y+1,curNode);
                this->checkPath(mazeMap,x,y-1,curNode);
            }
        }
        currentStep++;
    }
    //clear short path map
    this->shortPathPos.clear();
    //save the short path in map and delete node
    this->isShortPath(startNode);
    //because startNode is deleted, set it to null
    startNode=nullptr;
    if(!this->foundfinishNode){
        return -1;
    }
    return currentStep;
}

//Use deep first search to see if the path given is the shortest path
//delete node after finish checking
bool MazeSystem::isShortPath(GraphNode* node){
    bool foundPath = false;
    if(node != nullptr) {
        if(node->isFinishNode){
            savePath(node);
            foundPath = true;
        }else{
            while(!node->empty()){
                if(isShortPath(node->getLastNode())){
                    savePath(node);
                    foundPath = true;
                }
                node->removeLastNode();
            }
        }
        delete node;
    }
    return foundPath;
}

//check if the given position is out of bound
bool MazeSystem::isOutOfBound(vector<vector<Path*>>* mazeMap,int x,int y){
    return (mazeMap==nullptr||y<0||y>=mazeMap->size()||x<0||x>=(*mazeMap)[y].size());
}

//change position of player,
//return true if player successfully move to the given position
bool MazeSystem::changePosition(vector<vector<Path*>>* mazeMap,int x,int y,bool isUseStair){
    int costStep = this->checkPath(mazeMap,x,y);
    if(costStep == -1){
        return false;
    }
    if(!isUseStair){
        this->curStep += costStep;
    }
    this->curMazeMap = mazeMap;
    this->curX = x;
    this->curY = y;

    //if number of current steps is enough to trigger an event
    if(!isUseStair&&this->curStep%this->triggerStep==0){
        this->triggerEvent();
    }
    return true;
}

//save the path position to vector
void MazeSystem::savePath(GraphNode* node){
    int x = node->x;
    int y = node->y;
    vector<vector<Path*>>* mazeMap = node->mazeMap;
//    cout<<x<<" "<<y<<endl;
    if(mazeMap == this->curMazeMap){
        this->shortPathPos.push_back({x,y});
    }
}

//create maze map from read text file
void MazeSystem::createMap(ifstream& input){
    string str;
    getline(input,str);
    this->curX = stoi(str);
    getline(input,str); 
    this->curY = stoi(str);
    while(getline(input,str)){
        char c;
        int lengthX = stoi(str);
        getline(input,str);
        int widthY = stoi(str);
        vector<vector<Path*>>* lineY = new vector<vector<Path*>>();
        for(int i = 0;i < widthY;i++){
            vector<Path*> lineX;
            for(int j = 0;j < lengthX;j++){
                input>>noskipws>>c;
                //if it a stair add lineY to class
                Path* newPath = this->getPath(c,lineY,j,i);
                lineX.push_back(newPath);
            }
            input>>noskipws>>c;
            lineY->push_back(lineX);
        }
        if(curMazeMap == nullptr){
            curMazeMap = lineY;
        }
    }
}

//create stair event
void MazeSystem::createEvent(ifstream& inputEvent){
    string str;
    if(getline(inputEvent,str)){
        this->triggerStep = stoi(str);
        vector<vector<char>> curEvent;
        while(getline(inputEvent,str)){
            if(isalpha(str[0])){
                curEvent.push_back({str[0],str[2]});
            }else{
                this->qEventStair.push(curEvent);
                vector<vector<char>> newCurEvent;
                curEvent = newCurEvent;
            }
        }
    }
}

//changing the link between the stair
void MazeSystem::triggerEvent(){
    if(this->qEventStair.size()!=0){
        vector<vector<char>> curEvent = this->qEventStair.front();
        for(const auto& v : curEvent){
            string errorChar = "";
            if(this->stairMap.count(v[0])==0){
                errorChar = v[0];
            }else if(this->stairMap.count(v[1])==0){
                errorChar = v[1];
            }
            if(errorChar!=""){
                throw string("Stair "+errorChar+" does not exist in maze");
            }else{
                stairMap[v[0]]->setNextStair(stairMap[v[1]]);
                stairMap[v[1]]->setNextStair(stairMap[v[0]]);
            }
        }
        this->qEventStair.pop();
        this->qEventStair.push(curEvent);
//        cout<<"Event stair triggered"<<endl;
    }
}

void MazeSystem::resetFind(){
    this->foundfinishNode = false;
    this->recordMap.clear();
    //all node graph is already deleted
    while(!qGraph.empty()){
        qGraph.pop();
    }
}

Path* MazeSystem::getPath(char c,vector<vector<Path*>>* mazeMap, int x,int y){
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
        //if it a stair
        if(isalpha(toupper(c))){
            if(this->stairMap.count(toupper(c))){
                throw string("Duplicate stair exist");
            }else{
                newPath = new Stair(x,y,mazeMap);
                this->stairMap[c] = (Stair*) newPath;
            }
        }
        //if it is a obstacle
        else if(isdigit(c)){
            newPath = new Obstacle(c-'0');
        }
        else{
            throw string("Invalid symbol");
        }
        break;
    }
    return newPath;
}
//create a maze base on given txt file.
MazeSystem::MazeSystem(ifstream& inputMaze,ifstream& inputEvent){
    this->foundfinishNode = false;
    this->curMazeMap = nullptr;
    this->createMap(inputMaze);;
    this->createEvent(inputEvent);
    //create inital connection stair
    this->triggerEvent();
    this->curStep = 0;
//    //check system maze moving command
//    string input= "";
//    cout<<"Input your command: ";
//    cin>>input;
//    while(input!="exit"){
//        if(input=="a") this->moveLeft();
//        else if(input=="d") this->moveRight();
//        else if(input=="w") this->moveUp();
//        else if(input=="s") this->moveDown();
//        else if(input=="e") this->useStair();
//        else if(input=="f") {
//            int smallest_step = this->findShortPath(curX,curY);
//            cout<<"It should take "<<smallest_step<<" steps"<<endl;
//        }
//        cout<<"Current pos: "<<this->curX<<" "<<this->curY<<endl;
//        cout<<"Input your command: ";
//        cin>>input;
//    }
}

//destructor of MazeSystem
MazeSystem::~MazeSystem(){
    //delete every path
    for(auto kv : stairMap){
        vector<vector<Path*>>* maze = kv.second->mazeMap;
        for(int i = 0;i<maze->size();i++){
            for(int j = 0;j<(*maze)[i].size();j++){
                delete (*maze)[i][j];
            }
        }
        delete maze;
    }
    //delete GraphNode
    isShortPath(startNode);
}

//get path base on given x,y
Path* MazeSystem::get(int x, int y) const{
    return (*curMazeMap)[y][x];
}

//get path of user currently on
Path* MazeSystem::getUser() {
    return (*curMazeMap)[curY][curX];
}

//get type of the path base on given x,y
pathType MazeSystem::getType(int x, int y) const{
    return (*curMazeMap)[y][x]->getType();
}

//get color of the path base on given x, y
string MazeSystem::getColor(int x, int y) const {
    return (*curMazeMap)[y][x]->getColor();
}

//return the step cost when go to the given position
//return -1 if unable to go to the given position
int MazeSystem::checkPath(vector<vector<Path*>>* mazeMap,int x,int y){
    return this->checkPath(mazeMap,x,y,nullptr);
}

//return map that show shortest map for maze
//return vectors of position {x, y}
vector<vector<int>> MazeSystem::getMapDirection(){
    return this->shortPathPos;
}

//return length x of the maze map
int MazeSystem::getLength() const{
    if(this->curMazeMap->size() == 0) throw string("Maze not exist");
    return (*this->curMazeMap)[0].size();
}

//return width y of the maze map
int MazeSystem::getWidth() const{
    if(this->curMazeMap->size() == 0) throw string("Maze not exist");
    return this->curMazeMap->size();
}

//return the total stairs of this maze
int MazeSystem::getTotalStairs() const{
    return this->stairMap.size();
}

//return current position of x
int MazeSystem::getCurX() const{
    return this->curX;
}

//return current position of y
int MazeSystem::getCurY() const{
    return this->curY;
}

//return current position of z
vector<vector<Path*>>*  MazeSystem::getCurMaze() const{
    return this->curMazeMap;
}

//return current step player have make
int MazeSystem::getCurStep() const{
    return this->curStep;
}

//return remain step before trigger the event
int MazeSystem::stepRemain() const{
    if(this->curStep % this->triggerStep == 0) return 0;
    return this->triggerStep - (this->curStep%(this->triggerStep));
}

//move the player to the left
//return true if succesfully moved
bool MazeSystem::moveLeft(){
    return this->changePosition(this->curMazeMap,this->curX-1,this->curY,false);
}

//move the player to the right
//return true if succesfully moved
bool MazeSystem::moveRight(){
    return this->changePosition(this->curMazeMap,this->curX+1,this->curY,false);
}

//move the player up
//return true if succesfully moved
bool MazeSystem::moveUp(){
    return this->changePosition(this->curMazeMap,this->curX,this->curY-1,false);
}

//move the player down
//return true if succesfully moved
bool MazeSystem::moveDown(){
    return this->changePosition(this->curMazeMap,this->curX,this->curY+1,false);
}

//move the player to the next stair
//return true if succesfully moved
bool MazeSystem::useStair(){
    Path* curPath = (*this->curMazeMap)[this->curY][this->curX];
    if(curPath->getType() != stair){
        return false;
    }
    int nextX = ((Stair*)curPath)->getNextX();
    int nextY = ((Stair*)curPath)->getNextY();
    vector<vector<Path*>>* mazeMap = ((Stair*)curPath)->getNextMaze();
    return this->changePosition(mazeMap,nextX,nextY,true);
}
