#ifndef FOREST_H
#define FOREST_H

#include "terrain.h"

class forest:public terrain
{
public:
    forest(int x, int y);
    std::string getImage() const override;
};

#endif // FOREST_H
