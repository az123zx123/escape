#ifndef TERRAIN_H
#define TERRAIN_H

#include "piece.h"

class terrain: public piece{
    int cost;
    int index;
public:
    terrain(int x, int y, int cost,std::string image);
    int get_index();
    void set_index(int i);
    int get_cost();
};

#endif // TERRAIN_H
