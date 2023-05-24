
#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"


class FinishLine:public Path{
public:
    FinishLine();
    string getType() const;
    bool IsPassable();
    string getColor() const;
};

#endif // FINISHLINE_H
