
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"
#include <vector>
/*
 * The stair of the path which user can move to the next level of the maze
*/

class Stair:public Path{
private:
    const string DEFAULT_STAIR_COLOR = "yellow";
    int x;
    int y;
    Stair* next;
public:
    vector<vector<Path*>>* mazeMap;
    Stair(int x,int y,vector<vector<Path*>>* mazeMap);
    Stair(int x,int y,vector<vector<Path*>>* mazeMap,Stair* next);
    pathType getType() const;
    string getColor() const;
    int getNextX() const;
    int getNextY() const;
    vector<vector<Path*>>* getNextMaze() const;
    int getX() const;
    int getY() const;
    void setNextStair(Stair* stair);
};

#endif // STAIR_H
