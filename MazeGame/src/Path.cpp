
#include "Path.h"
using namespace std;

Path::Path(int x,int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}
Path::Path(int x,int y, int z,Path* prev){
    this->x = x;
    this->y = y;
    this->z = z;
    this->prev = prev;
}
Path* Path::getPrevPath(){
    return this->prev;
}
void Path::setPrevPath(Path* prev){
    this->prev = prev;
}
pathType Path::getType() const{
    return path;
}

string Path::getColor() const{
    return DEFAULT_PATH_COLOR;
}

bool Path::IsPassable(){
    return true;
}