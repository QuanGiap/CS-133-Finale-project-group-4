
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"
const string DEFAULT_STAIR_COLOR = "white";

class Stair:public Path{
private:
    int toX;
    int toY;
    int toZ;
    char stairType;
public:
    Stair(int toX,int toY,int toZ,char stairType);
    char getStairType()const;
    pathType getType() const;
    string getColor() const;
    int getToX() const;
    int getToY() const;
    int getToZ() const;
};

#endif // STAIR_H
