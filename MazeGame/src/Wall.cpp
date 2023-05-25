
#include "Wall.h"

Wall::Wall(int x ,int y,int z):Path(x,y,z){};
Wall::Wall(int x ,int y,int z,Path* prev):Path(x,y,z,prev){};

pathType Wall::getType() const{
    return wall;
}

string Wall::getColor() const{
    return DEFAULT_WALL_COLOR;
}

bool Wall::IsPassable(){
    return false;
}

