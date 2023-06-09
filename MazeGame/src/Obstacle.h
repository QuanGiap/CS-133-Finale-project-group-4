
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Path.h"
/*
 * obstacle of the path which take more step than normal one
*/

class Obstacle:public Path{
private:
    string DEFAULT_OBSTACLE_COLOR = "black";
    int costStep;
public:
    Obstacle(int costStep);
    pathType getType() const;
    string getColor() const;
//  return the cost step to pass this path
    int getCostStep() const;
};

#endif // OBSTACLE_H
