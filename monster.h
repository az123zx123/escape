#ifndef MONSTER_H
#define MONSTER_H

#include "QTimer"
#include "piece.h"
#include "character.h"
#include "terrain.h"

class monster: public character
{
    Q_OBJECT
    terrain* (*pieceBoard)[8][8];
    character* (*locationBoard)[8][8];
public:
    QTimer moveTimer;
    monster(int x, int y, terrain* (*pieceBoard)[8][8], character* (*locationBoard)[8][8]);
    void potentialMove(bool potentialMove[8][8]);
    bool move(int x, int y);   //1. move the hero in the locationBoard
//    2. calculate the time according to pieceBoard
//    3.set the can_move to false, use timer to reset the can_move, timeInterval can refer to time
    bool can_move;
    std::string getImage() const override;
signals:
    void capture();
public slots:
    void start_move();  //connect start_move to game_start
};

#endif // MONSTER_H
