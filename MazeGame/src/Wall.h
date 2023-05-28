
#ifndef WALL_H
#define WALL_H

#include "Path.h"

class Wall:public Path{
    const string DEFAULT_WALL_COLOR = "black";
public:
    Wall();
    pathType getType() const;
    string getColor() const;
    int getCostStep() const;
};

#endif // WALL_H
