
#include "Road.h"

/*
 * Road path where user can walk on
*/

// constructs a road object
Road::Road(){};

// Returns a pathType of road
pathType Road::getType() const{
    return road;
}

// returns DEFAULT_ROAD_COLOR
string Road::getColor() const{
    return DEFAULT_ROAD_COLOR;
}
