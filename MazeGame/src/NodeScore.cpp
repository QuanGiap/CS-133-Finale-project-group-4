// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#include "NodeScore.h"

/*
 * A node linked present the user name and score
*/

NodeScore::NodeScore(string name,int score)
{
    this->name = name;
    this->score = score;
    this->next = nullptr;
}

NodeScore::NodeScore(string name,int score,NodeScore* next)
{
    this->name = name;
    this->score = score;
    this->next = next;
}
