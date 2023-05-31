
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

//bool Path::isUser() const {
//    return user;
//}

//void Path::toggleUser() {
//    user = !user;
//}
