#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include <QFont>

#include "piece.h"

namespace Ui {
class GameWindow;
}

class Square;
class gameinstance;

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr, gameinstance* _chess_game=nullptr);
    ~GameWindow();

    static const int COIN_LCD = 0;
    static const int STEP_LCD = 1;
    gameinstance* get_game() const;
    Square* get_square(int row, int col) const;
    void set_highlighted(int row, int col, bool value, std::string color="black");
    void reset_highlighted();
    void set_icon(int row, int col, std::string i);
    void show_reach_target();
    void set_lcd(int type, int value);

private:
    void closeEvent(QCloseEvent *event);
    void make_grid();

    Ui::GameWindow *ui;
    Square* square[8][8];
    gameinstance* game;

signals:
    void closed();
    void win();
};

#endif // GAMEWINDOW_H
