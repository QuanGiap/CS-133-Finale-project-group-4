
#include "Road.h"

Road::Road(int x,int y, int z):Path(x,y,z){};
Road::Road(int x,int y, int z, Path* prev):Path(x,y,z,prev){};

pathType Road::getType() const{
    return road;
}

string Road::getColor() const{
    return DEFAULT_ROAD_COLOR;
}

bool Road::IsPassable(){
    return true;
}
