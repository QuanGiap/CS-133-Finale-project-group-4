// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

// This file implements the functions given in FinishLine.h


#include "FinishLine.h"

FinishLine::FinishLine(){}

pathType FinishLine::getType() const{
    return finishPoint;
}

string FinishLine::getColor() const{
    return DEFAULT_FINISH_LINE_COLOR;
}
