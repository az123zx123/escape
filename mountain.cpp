#include "mountain.h"

mountain::mountain(int x,int y):terrain(x,y,10,"mountain")
{

}

std::string mountain::getImage() const{
    return "mountain";
}
