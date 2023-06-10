// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

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
    //add node to score board
    //sort the node from the smallest to the biggest score
    void add(NodeScore* node);

    //create node from name and score,
    //add to score board
    //sort the node from the smallest to the biggest score
    void add(string name,int score);

    //return string that show rank of each user
    string toString();
};

#endif // SCOREBOARD_H
