
#ifndef WALL_H
#define WALL_H

#include "Path.h"
const string DEFAULT_WALL_COLOR = "black";

class Wall:public Path{
public:
    Wall();
    pathType getType() const;
    string getColor() const;
    int getCostStep() const;
};

#endif // WALL_H
