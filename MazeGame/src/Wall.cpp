
#include "Wall.h"

Wall::Wall(){};

pathType Wall::getType() const{
    return wall;
}

string Wall::getColor() const{
    return DEFAULT_WALL_COLOR;
}

int Wall::getCostStep() const{
    return -1;
}

