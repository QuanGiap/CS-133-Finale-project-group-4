
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
pathType Stair::getType() const{
    return stair;
}

string Stair::getColor() const{
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
