#include "forest.h"

forest::forest(int x,int y):terrain (x,y,3,"forest")
{

}

std::string forest::getImage() const{
    return "forest";
}
