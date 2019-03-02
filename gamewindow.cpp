#include <QFont>
#include <string>
#include <QDebug>

#include "ui_gamewindow.h"
#include "square.h"
#include "gameinstance.h"
#include "gamewindow.h"

using std::string;

//extern QFont* chess_font;

GameWindow::GameWindow(QWidget *parent, gameinstance* _chess_game) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    game(_chess_game)
{
    for(int i=0;i<64;++i)
        this->square[i/8][i%8] = nullptr;
//    ui->setupUi(this);
//    ui->bIndicator->close();
//    ui->wIndicator->close();
//    this->make_grid();
//    ui->checkmate->close();
//    ui->stalemate->close();
    ui->setupUi(this);
    this->make_grid();
    show();
}

GameWindow::~GameWindow() {
    delete ui;
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++){
            if(square[i][j]!=nullptr)
                delete square[i][j];
         square[i][j]=nullptr;
        }
}

void GameWindow::closeEvent(QCloseEvent *event) {
    emit closed();
}

void GameWindow::make_grid() {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            this->square[i][j] = new Square(this, i, j);
        }
    }
}

void GameWindow::set_lcd(int type, int value)
{
    QLCDNumber *lcds[2] = {ui -> COIN_LCD, ui -> STEP_LCD};
    lcds[type] -> display(value);
    lcds[type] -> show();
}

Square* GameWindow::get_square(int row, int col) const {
    return this->square[row][col];
}

void GameWindow::set_highlighted(int row, int col, bool value, string color) {
    this->square[row][col]->set_highlighted(value, color);
}

void GameWindow::reset_highlighted() {
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            if(this->square[i][j]!=nullptr)
            (square)[i][j]->set_highlighted(false,"black");}
    }
}
void GameWindow::set_icon(int row, int col, string i) {
    this->square[row][col]->set_icon(i);
}
