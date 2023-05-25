
#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;
const string DEFAULT_PATH_COLOR = "white";

enum pathType{
    path,
    startPoint,
    finishPoint,
    obstacle,
    road,
    stair,
    wall
};

class Path{
    int x;
    int y;
    int z;
    Path* prev;
public:
    Path(int x,int y, int z);
    Path(int x,int y, int z, Path* prev);
    Path* getPrevPath();
    void setPrevPath(Path* prev);
    virtual pathType getType() const = 0;
    virtual string getColor() const = 0;
    virtual bool IsPassable();
};

#endif // PATH_H
