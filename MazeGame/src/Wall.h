// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#ifndef WALL_H
#define WALL_H

#include "Path.h"

/*
 * The wall of the path which user can't move
 */

class Wall:public Path{
    const string DEFAULT_WALL_COLOR = "black";
public:

    // Constructs a wall object
    Wall();

    // Returns a pathType of wall
    pathType getType() const;

    // returns a string DEFAULT_WALL_COLOR
    string getColor() const;

    // returns a cost step of -1
    int getCostStep() const;
};

#endif // WALL_H
