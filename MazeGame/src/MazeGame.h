
#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <vector>
#include "Path.h"
#include <iostream>
#include <unordered_map>
#include "LinkedNode.h"
using namespace std;

class MazeGame{
private:
    vector<vector<vector<Path*>>>* mazeMap;
    unordered_map<int,vector<LinkedNode>> mapLinked;
public:
    MazeGame(string fileName);
    bool isValidMaze();
    void startGame();
    void showPath();
};

#endif // MAZEGAME_H
