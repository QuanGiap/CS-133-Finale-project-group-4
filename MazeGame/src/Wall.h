
#ifndef WALL_H
#define WALL_H

#include "Path.h"


class Wall:public Path{
public:
    Wall();
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // WALL_H
