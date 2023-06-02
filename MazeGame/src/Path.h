
#ifndef PATH_H
#define PATH_H
#include <iostream>
using namespace std;
const string DEFAULT_PATH_COLOR = "white";
const string USER_COLOR = "green";
const string ALGO_COLOR = "blue";

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
    const string DEFAULT_PATH_COLOR = "white";
private:
  //  bool user;
public:
    //constructor of path
    Path();
    //destructor of path
    virtual ~Path() = default;
    //return enum pathType (return path)
    virtual pathType getType() const = 0;
    //return string color for path which is use for GUI
    virtual string getColor() const = 0;
    //return cost step to get this path
    virtual int getCostStep() const;
};

#endif // PATH_H
