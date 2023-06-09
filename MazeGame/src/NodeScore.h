// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#ifndef NODESCORE_H
#define NODESCORE_H
#include <iostream>
using namespace std;
/*
 * A node linked present the user name and score
*/

class NodeScore
{
public:
    string name;
    int score;
    NodeScore* next;
    NodeScore(string name,int score);
    NodeScore(string name,int score,NodeScore* next);
};

#endif // NODESCORE_H
