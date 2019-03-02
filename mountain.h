#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "terrain.h"

class mountain:public terrain
{
public:
    mountain(int x, int y);
    std::string getImage() const override;
};

#endif // MOUNTAIN_H
