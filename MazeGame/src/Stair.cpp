// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

#include "Stair.h"
//Represents the stair object in the maze, it stores the position of the stair,next stair, 
//and maze map

Stair::Stair(int x,int y,vector<vector<Path*>>* mazeMap){
    this->x = x;
    this->y = y;
    this->next = nullptr;
    this->mazeMap=mazeMap;
}
Stair::Stair(int x,int y,vector<vector<Path*>>* mazeMap,Stair* next){
    this->x = x;
    this->y = y;
    this->mazeMap=mazeMap;
    this->next = next;
}
pathType Stair::getType() const{
    return stair;
}

string Stair::getColor() const{
    return DEFAULT_STAIR_COLOR;
}

int Stair::getNextX() const{
    return this->next->x;
}
int Stair::getNextY() const{
    return this->next->y;
} 
//Returns a pointer to the maze map of the next stair
vector<vector<Path*>>* Stair::getNextMaze(){
    return this->next->mazeMap;
}
//Returns the x-coordinate of the current stair
int Stair::getX() const{
    return this->x;
}
//Returns the y-coordinate of the current stair
int Stair::getY() const{
    return this->y;
}

//Sets the next stair in the maze
void Stair::setNextStair(Stair* stair){
    this->next = stair;
}
