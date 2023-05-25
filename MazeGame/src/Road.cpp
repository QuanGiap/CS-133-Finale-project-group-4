
#include "Road.h"

Road::Road(){};

pathType Road::getType() const{
    return road;
}

string Road::getColor() const{
    return DEFAULT_ROAD_COLOR;
}
