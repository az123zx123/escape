#ifndef END_POINT_H
#define END_POINT_H

#include "terrain.h"

class end_point: public terrain
{
public:
    end_point(int x, int y);
    std::string getImage() const override;
};

#endif // END_POINT_H
