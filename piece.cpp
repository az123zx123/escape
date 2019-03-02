#include "piece.h"


piece::piece(int x, int y, std::string image):x(x),y(y),image(image){
}

int piece::get_x(){
    return x;
}

int piece::get_y(){
    return y;
}

void piece::set_x(int x){
    this->x=x;
    return;
}

void piece::set_y(int y){
    this->y=y;
    return;
}
