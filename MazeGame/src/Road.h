
#ifndef ROAD_H
#define ROAD_H
#include "Path.h"

class Road:public Path{
    const string DEFAULT_ROAD_COLOR = "white";
public:
    Road();
    pathType getType() const;
    string getColor() const;
};

#endif // ROAD_H
