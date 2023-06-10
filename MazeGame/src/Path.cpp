// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#include "Path.h"
using namespace std;

Path::Path() {};
pathType Path::getType() const{
    return path;
}

string Path::getColor() const{
    return DEFAULT_PATH_COLOR;
}

int Path::getCostStep() const{
    return 1;
}
