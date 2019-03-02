#ifndef MOOR_H
#define MOOR_H

#include "terrain.h"

class moor:public terrain
{
public:
    moor(int x, int y);
    std::string getImage() const override;
};

#endif // MOOR_H
