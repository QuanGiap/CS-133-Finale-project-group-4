
#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"


class FinishLine:public Path{
    const string DEFAULT_FINISH_LINE_COLOR = "orange";
public:
    FinishLine();
    pathType getType() const;
    string getColor() const;
};

#endif // FINISHLINE_H
