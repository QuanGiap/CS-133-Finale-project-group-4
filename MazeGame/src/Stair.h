
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"


class Stair:public Path{
public:
    Stair();
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // STAIR_H
