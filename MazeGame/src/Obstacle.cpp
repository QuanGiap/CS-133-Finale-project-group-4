#include "Obstacle.h"

/*
 * obstacle of the path which take more step than normal one
*/

Obstacle::Obstacle(int costStep){
    this->costStep = costStep;
}

pathType Obstacle::getType() const{
    return obstacle;
}

string Obstacle::getColor() const{
    return DEFAULT_OBSTACLE_COLOR;
}

int Obstacle::getCostStep()const{
    return this->costStep;
}
