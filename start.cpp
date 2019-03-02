#include "start.h"

start::start(int x,int y):terrain(x,y,0,"start"){
}

std::string start::getImage() const{
    return "start";
}
