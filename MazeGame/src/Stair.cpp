
#include "Stair.h"

Stair::Stair(int toX,int toY,int toZ,char stairType){
    this->toX = toX;
    this->toY = toY;
    this->toZ = toZ;
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
