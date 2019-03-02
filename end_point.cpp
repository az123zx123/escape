#include "end_point.h"

end_point::end_point(int x, int y):terrain(x,y,0,"end"){
}

std::string end_point::getImage() const{
    return "end";
}
