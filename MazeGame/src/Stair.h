
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"

class Stair:public Path{
private:
    const string DEFAULT_STAIR_COLOR = "white";
    int x;
    int y;
    int z;
    Stair* next;
public:
    Stair(int X,int Y,int Z);
    Stair(int X,int Y,int Z,Stair* next);
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
