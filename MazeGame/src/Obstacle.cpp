
#include "Obstacle.h"

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
