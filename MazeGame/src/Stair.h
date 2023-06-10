// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

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
    //A pointer to the maze map of the next stair
    vector<vector<Path*>>* getNextMaze();
    int getX() const;
    int getY() const;
    void setNextStair(Stair* stair);
};

#endif // STAIR_H
