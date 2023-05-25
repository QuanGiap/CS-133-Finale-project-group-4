
#ifndef WALL_H
#define WALL_H

#include "Path.h"
const string DEFAULT_WALL_COLOR = "black";

class Wall:public Path{
public:
    Wall(int x,int y, int z);
    Wall(int x,int y, int z,Path* prev);
    pathType getType() const;
    string getColor() const;
    bool IsPassable();
};

#endif // WALL_H
