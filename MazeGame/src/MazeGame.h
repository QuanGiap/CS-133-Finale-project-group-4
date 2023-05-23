
#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <vector>
#include "Path.h"
#include <iostream>
using namespace std;

class MazeGame{
private:
    vector<vector<vector<Path>>>* mazeMap;
public:
    MazeGame(string fileName);
    bool isValidMaze();
    void startGame();
    bool guessStep(int step);
    void showPath();
};

#endif // MAZEGAME_H
