#include "grass.h"

grass::grass(int x,int y):terrain(x,y,1,"grass")
{

}

std::string grass::getImage() const{
    return "grass";
}
