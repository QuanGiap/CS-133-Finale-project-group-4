
#ifndef ROAD_H
#define ROAD_H
#include "Path.h"

const string DEFAULT_ROAD_COLOR = "white";
class Road:public Path{
public:
    Road(int x,int y, int z);
    Road(int x,int y, int z, Path* prev);
    pathType getType() const;
    string getColor() const;
    bool IsPassable();
};

#endif // ROAD_H
