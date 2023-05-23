
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Path.h"


class Obstacle:public Path{
public:
    Obstacle();
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // OBSTACLE_H
