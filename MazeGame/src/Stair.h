
#ifndef STAIR_H
#define STAIR_H

#include "Path.h"
#include <vector>

class Stair:public Path{
private:
    const string DEFAULT_STAIR_COLOR = "yellow";
    int x;
    int y;
    Stair* next;
    vector<vector<Path*>>* mazeMap;
public:
    Stair(int x,int y,vector<vector<Path*>>* mazeMap);
    Stair(int x,int y,vector<vector<Path*>>* mazeMap,Stair* next);
    ~Stair();
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
