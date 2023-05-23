
#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;



class Path{
public:
    Path();
    virtual string getType() const = 0;
    virtual string getColor() const = 0;
    virtual bool IsPassable();
};

#endif // PATH_H
