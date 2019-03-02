#include "treasure.h"

treasure::treasure(int x, int y, int value,terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]):character(x,y,"treasure"){
    this->pieceBoard=pieceBoard;
    this->locationBoard=locationBoard;
    this->value=value;
}

int treasure::get_value(){
    return value;
}

std::string treasure::getImage() const{
    return "treasure";
}
