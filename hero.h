#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "QTimer"
#include "terrain.h"

class hero: public character
{
    Q_OBJECT
    terrain* (*pieceBoard)[8][8];
    character* (*locationBoard)[8][8];
    int time{0};
public:
    QTimer* moveTimer;
    hero(int x, int y, terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]);
    void potentialMove(bool potentialMove[8][8]);
    piece* move(int x, int y);   //1. move the hero in the locationBoard
//    2. calculate the time according to pieceBoard
//    3.set the can_move to false, use timer to reset the can_move, timeInterval can refer to time
    int get_time();
    std::string getImage() const override;
};

#endif // HERO_H
