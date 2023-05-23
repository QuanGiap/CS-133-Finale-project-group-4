
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"


class Stair:public Path{
private:
    int goX;
    int goY;
    int goZ;
    char stairType;
public:
    Stair(int x,int y,int z,char stairType);
    char getStairType()const;
    string getType() const;
    bool IsPassable();
    string getColor() const;
};

#endif // STAIR_H
