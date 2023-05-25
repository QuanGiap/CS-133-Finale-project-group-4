
#include "FinishLine.h"

FinishLine::FinishLine(){}

pathType FinishLine::getType() const{
    return finishPoint;
}

string FinishLine::getColor() const{
    return DEFAULT_FINISH_LINE_COLOR;
}
