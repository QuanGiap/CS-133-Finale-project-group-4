
#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;



class Path{
protected:
    int x;
    int y;
    Path* prev;
public:
    Path();
    Path(Path* prev);
    int getX();
    int getY();
    virtual string getType() = 0;
    virtual string getColor() = 0;
    virtual bool IsPassable();
};

#endif // PATH_H
