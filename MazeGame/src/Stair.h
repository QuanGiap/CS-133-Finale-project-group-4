
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"
const string DEFAULT_STAIR_COLOR = "white";

class Stair:public Path{
private:
    int x;
    int y;
    int z;
    Stair* next;
public:
    Stair(int toX,int toY,int toZ);
    Stair(int toX,int toY,int toZ,Stair* next);
    pathType getType() const;
    string getColor() const;
    int getNextX() const;
    int getNextY() const;
    int getNextZ() const;
    int getX() const;
    int getY() const;
    int getZ() const;
    void setNextStair(Stair* stair);
};

#endif // STAIR_H
