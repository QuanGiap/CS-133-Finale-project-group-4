// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

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
