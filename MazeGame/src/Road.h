
#ifndef ROAD_H
#define ROAD_H
#include "Path.h"

class Road:public Path{
    const string DEFAULT_ROAD_COLOR = "white";
public:
    // constructs a road object
    Road();
    // Returns a pathType of road
    pathType getType() const;
    // returns DEFAULT_ROAD_COLOR
    string getColor() const;
};

#endif // ROAD_H
