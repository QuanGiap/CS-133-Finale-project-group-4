
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Path.h"
string DEFAULT_OBSTACLE_COLOR = "white";


class Obstacle:public Path{
private:
    int costStep;
public:
    Obstacle(int costStep);
    pathType getType() const;
    string getColor() const;
//  return the cost step to pass this path
    int getCostStep() const;
};

#endif // OBSTACLE_H
