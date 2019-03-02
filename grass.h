#ifndef GRASS_H
#define GRASS_H

#include "terrain.h"

class grass:public terrain
{
public:
    grass(int x, int y);
    std::string getImage() const override;
};

#endif // GRASS_H
