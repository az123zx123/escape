#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QtWidgets/QMessageBox>
#include <QApplication>
#include <QtWidgets/QApplication>

#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class gameinstance;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer* player;
    QMediaPlaylist* musicList;

private:
    Ui::MainWindow *ui;
    gameinstance* game;

private slots:
    void startButton_clicked_handler();
    void game_window_closed_handler();
    void tutorial();
};

#endif // MAINWINDOW_H
