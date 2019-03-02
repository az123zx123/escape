#include "moor.h"

moor::moor(int x,int y):terrain (x,y,5,"moor")
{

}

std::string moor::getImage() const{
    return "moor";
}
