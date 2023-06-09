#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include "NodeScore.h"
using namespace std;

/*
*/

class ScoreBoard
{
    NodeScore* header;
public:
    ScoreBoard();
    ~ScoreBoard();
    void add(NodeScore* node);
    void add(string name,int score);
    string toString();
};

#endif // SCOREBOARD_H
