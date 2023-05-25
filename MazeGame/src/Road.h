
#ifndef ROAD_H
#define ROAD_H
#include "Path.h"

const string DEFAULT_ROAD_COLOR = "white";
class Road:public Path{
public:
    Road();
    pathType getType() const;
    string getColor() const;
};

#endif // ROAD_H
