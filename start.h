#ifndef START_H
#define START_H

#include "terrain.h"

class start: public terrain
{
public:
    start(int x, int y);
    std::string getImage() const override;
};

#endif // START_H
