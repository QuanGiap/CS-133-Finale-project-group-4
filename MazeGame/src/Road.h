// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#ifndef ROAD_H
#define ROAD_H
#include "Path.h"

/*
 * Road path where user can walk on
*/

class Road:public Path{
private:
    const string DEFAULT_ROAD_COLOR = "white";
public:
    // constructs a road object
    Road();
    // Returns a pathType of road
    pathType getType() const;
    // returns DEFAULT_ROAD_COLOR
    string getColor() const;
};

#endif // ROAD_H
