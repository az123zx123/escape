#include <QFont>
#include <QFontDatabase>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMediaPlayer"
#include "gameinstance.h"

//QFont* chess_font;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(nullptr)
{
    ui->setupUi(this);
    connect(this->ui->startButton, &QPushButton::clicked, this, &MainWindow::startButton_clicked_handler);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(tutorial()));
    musicList = new QMediaPlaylist();
    musicList->addMedia(QUrl("qrc:/music/begin.mp3"));
    musicList->setPlaybackMode(QMediaPlaylist::Loop);
    player = new QMediaPlayer();
    player->setPlaylist(musicList);
    player->setVolume(30);
    player->play();
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

void MainWindow::startButton_clicked_handler()
{
    player->stop();
    if(this->game!=nullptr) delete this->game;
    this->game = new gameinstance;
    this->game->startGraphicUI();
    connect(this->game->get_game_window(), &GameWindow::closed, this, &MainWindow::game_window_closed_handler);
    this->hide();
}

void MainWindow::game_window_closed_handler() {
    cout<<"show"<<endl;
    this->show();
//    cout<<"show"<<endl;
    player->play();
//    cout<<"show"<<endl;
//    if (this->game!=nullptr) {cout<<"delete this game"<<endl;
//        delete this->game;
//    cout<<"deleted this game"<<endl;
//    }
//    this->game = nullptr;
//    cout<<"show"<<endl;
}

void MainWindow::tutorial(){
    QMessageBox::information(this,"tutorial","goal: reach the end and use as little time as possible.remember to avoid monster");
    QMessageBox::information(this,"tutorial","move: click square near hero.\ntreasure:you can collect them during journey");
}
