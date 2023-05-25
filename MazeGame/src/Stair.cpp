
#include "Stair.h"

Stair::Stair(int x,int y,int z,int toX,int toY,int toZ,char stairType):Path(x,y,z){
    this->toX = x;
    this->toY = x;
    this->toZ = x;
    this->stairType = stairType;
}
Stair::Stair(int x,int y,int z, Path* prev,int toX,int toY,int toZ,char stairType):Path(x,y,z,prev){
    this->toX = x;
    this->toY = x;
    this->toZ = x;
    this->stairType = stairType;
}
char Stair::getStairType()const{
    return this->stairType;
}
pathType Stair::getType() const{
    return stair;
}
string Stair::getColor() const{
    return DEFAULT_STAIR_COLOR;
}
int Stair::getToX() const{
    return this->toX;
}
int Stair::getToY() const{
    return this->toY;
}
int Stair::getToZ() const{
    return this->toZ;
}
