
#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"

const string DEFAULT_FINISH_LINE_COLOR = "orange";

class FinishLine:public Path{
public:
    FinishLine();
    pathType getType() const;
    string getColor() const;
};

#endif // FINISHLINE_H
