
#ifndef FINISHLINE_H
#define FINISHLINE_H

#include "Path.h"
/*
 * Finish line of the path
*/

class FinishLine:public Path{
    const string DEFAULT_FINISH_LINE_COLOR = "blue";
public:
    FinishLine();
    pathType getType() const;
    string getColor() const;
};

#endif // FINISHLINE_H
