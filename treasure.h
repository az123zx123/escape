#ifndef TREASURE_H
#define TREASURE_H

#include "character.h"
#include "terrain.h"

class treasure: public character
{
    int value;
    terrain* (*pieceBoard)[8][8];
    character* (*locationBoard)[8][8];
public:
    treasure(int x, int y, int value,terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]);
    int get_value();
    std::string getImage() const override;
};

#endif // TREASURE_H
