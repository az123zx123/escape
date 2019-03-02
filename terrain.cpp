#include "terrain.h"

terrain::terrain(int x, int y, int cost,std::string image):piece(x,y,image),cost(cost){
}


int terrain::get_index(){
    return index;
}

void terrain::set_index(int i){
    index=i;
}

int terrain::get_cost(){
    return cost;
}
