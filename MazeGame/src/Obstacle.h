// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Path.h"
/*
 * Obstacle in the maze which takes more steps to move past
 * 
*/

class Obstacle:public Path{
private:
    const string DEFAULT_OBSTACLE_COLOR = "black";
    int costStep;
public:
    Obstacle(int costStep);
    pathType getType() const;
    string getColor() const;
//  return the cost step to pass this path
    int getCostStep() const;
};

#endif // OBSTACLE_H
