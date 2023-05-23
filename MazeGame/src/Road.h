
#ifndef ROAD_H
#define ROAD_H


#include "Path.h"

class Road:public Path{
public:
    Road();
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // ROAD_H
