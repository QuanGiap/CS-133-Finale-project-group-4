
#include "Stair.h"

Stair::Stair(int x,int y,int z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->next = nullptr;
}
Stair::Stair(int x,int y,int z,Stair* next){
    this->x = x;
    this->y = y;
    this->z = z;
    this->next = next;
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
int Stair::getNextZ() const{
    return this->next->z;
}
int Stair::getX() const{
    return this->x;
}
int Stair::getY() const{
    return this->y;
}
int Stair::getZ() const{
    return this->z;
}

void Stair::setNextStair(Stair* stair){
    this->next = stair;
}
