#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include "NodeScore.h"
using namespace std;

/*
 * A board that can shows which user name have the least score
 * It is rank from the smallest to the biggest score
*/

class ScoreBoard
{
    NodeScore* header;
public:
    ScoreBoard();
    ~ScoreBoard();
    //add node to score board and sort the node
    void add(NodeScore* node);

    //create node from name and score,
    //add to score board and sort the node
    void add(string name,int score);

    //return string that show rank of each user
    string toString();
};

#endif // SCOREBOARD_H
