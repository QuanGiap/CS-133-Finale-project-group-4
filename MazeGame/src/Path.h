
#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;
const string DEFAULT_PATH_COLOR = "white";

//enum for different kind of paths
enum pathType{
    path,
    finishPoint,
    obstacle,
    road,
    stair,
    wall
};

//a parent class to set up different kind of paths
class Path{
public:
    //constructor of path
    Path();
    //return enum pathType (return path)
    virtual pathType getType() const = 0;
    //return string color for path which is use for GUI
    virtual string getColor() const = 0;
    //return bool if user can pass this path
    virtual bool IsPassable() const;
};

#endif // PATH_H
