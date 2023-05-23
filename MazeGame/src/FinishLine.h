
#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"


class FinishLine:public Path{
public:
    FinishLine();
    string getType();
    bool IsPassable();
    string getColor();
};

#endif // FINISHLINE_H
