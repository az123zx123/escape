#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
#include <stdlib.h>
#include <time.h>
using std::fill_n;

#include <QObject>
#include <QMessageBox>
#include <QtWidgets/QMessageBox>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QDebug>
#include "QMediaPlayer"
#include "QMediaPlaylist"

#include "terrain.h"
#include "piece.h"
#include "character.h"
#include "a_star.h"
#include "gamewindow.h"
#include "treasure.h"
#include "start.h"
#include "hero.h"
#include "monster.h"
#include "end_point.h"
#include "random"
#include "grass.h"
#include "mountain.h"
#include "moor.h"
#include "forest.h"
#include "square.h"

class GameWindow;

class gameinstance: public QObject
{
    Q_OBJECT
private:
    QTimer* routine_timer;
    GameWindow* game_window; // The GUI.
    terrain* pieceBoard[8][8]; // The internal ChessBoard. Passed to all Pieces, as the backgroud
    character* locationBoard[8][8];// The location about hero, treasure and monster
    graph* map; //weight is the cost inward the terrain
    void random_map();
    bool least_time_way[8][8];
    void predict_way(bool least_time_way[8][8]);
    void reset_icon(int x,int y);
    int selected_x{0};
    int selected_y{0};
    int monster_move_counter{0};
    void show_least_time_way();
    QMediaPlayer* player;
    QMediaPlaylist* musicList;
    int minimum_cost{0};
public:
    gameinstance();
    ~gameinstance();
    void startGraphicUI(); // GUI Entry Point.
    GameWindow* get_game_window() const;
    int time_remain{0};
    int treasure_num{0};
    A_star* predict;
    hero* hero_p;
    monster* monster_p;
    monster* additional_monster;
signals:
    void game_start();
    void finish();

private slots:
    void processUserInput(int row, int col); // Connect to clicked_with_pos() signal to get coordinates of the clicked ChessBoard square.
    void monster_random(monster* monster); //handle monster randomly move
    void game_over();
    void routine();
    void game_win();
    void game_close();
    void main_thread();
};

#endif // GAMEINSTANCE_H
