// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

// This class represents the finish point of the maze


#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"


class FinishLine:public Path{
    const string DEFAULT_FINISH_LINE_COLOR = "blue";
public:
    FinishLine();
    pathType getType() const;
    string getColor() const;
};

#endif // FINISHLINE_H
