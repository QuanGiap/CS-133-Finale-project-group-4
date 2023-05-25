
#include "Wall.h"

Wall::Wall(){};

pathType Wall::getType() const{
    return wall;
}

string Wall::getColor() const{
    return DEFAULT_WALL_COLOR;
}

bool Wall::IsPassable() const{
    return false;
}

