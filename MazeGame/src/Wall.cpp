#include "Wall.h"

// Constructs a wall object
Wall::Wall(){};

// Returns a pathType of wall
pathType Wall::getType() const{
    return wall;
}

// returns a string DEFAULT_WALL_COLOR
string Wall::getColor() const{
    return DEFAULT_WALL_COLOR;
}

// returns a cost step of -1
int Wall::getCostStep() const{
    return -1;
}

