
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Path.h"


class Obstacle:public Path{
private:
    int costStep;
public:
    Obstacle(int costStep);
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // OBSTACLE_H
