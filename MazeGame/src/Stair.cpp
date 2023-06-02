
#include "Stair.h"

Stair::Stair(int x,int y,vector<vector<Path*>>* mazeMap){
    this->x = x;
    this->y = y;
    this->next = nullptr;
    this->mazeMap=mazeMap;
}
Stair::Stair(int x,int y,vector<vector<Path*>>* mazeMap,Stair* next){
    this->x = x;
    this->y = y;
    this->mazeMap=mazeMap;
    this->next = next;
}
Stair::~Stair(){
    if(this->mazeMap!=nullptr){
        for(int y = 0;y < this->mazeMap->size();y++){
            for(int x = 0;x < (*this->mazeMap)[y].size();x++){
                if((*this->mazeMap)[y][x]!=nullptr) delete (*this->mazeMap)[y][x];
            }
        }
        delete this->mazeMap;
    }
}
pathType Stair::getType() const{
    return stair;
}
//string Stair::getColor() const{
//    return DEFAULT_STAIR_COLOR;
//}

string Stair::getColor() const{
//    if(isUser()) {
//        return USER_COLOR;
//    }
    return DEFAULT_STAIR_COLOR;
}

int Stair::getNextX() const{
    return this->next->x;
}
int Stair::getNextY() const{
    return this->next->y;
}
vector<vector<Path*>>* Stair::getNextMaze() const{
    return this->next->mazeMap;
}
int Stair::getX() const{
    return this->x;
}
int Stair::getY() const{
    return this->y;
}

void Stair::setNextStair(Stair* stair){
    this->next = stair;
}
