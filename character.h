#ifndef CHARACTER_H
#define CHARACTER_H

#include "piece.h"

class character: public piece
{
    Q_OBJECT
public:
    character(int x, int y,std::string image);
};

#endif // CHARACTER_H
