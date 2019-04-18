#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "player.h"
#include "enemy.h"
#include <QPaintEvent>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMediaPlaylist>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    bool gameStart=0;
    bool shoot=0;
    void bulletSound();
     QMediaPlayer* media = new QMediaPlayer();
     QMediaPlaylist* playlist = new QMediaPlaylist;
     int x = 50;
     int y = 50;

private:
    Ui::MainWindow *ui;
    QPixmap* background;
    player* player_one;
    enemy* enemy;
    int direction =0;


protected:
void paintEvent(QPaintEvent *e);
void keyPressEvent(QKeyEvent *evt);



private slots:
void on_titleStart_clicked();
void updateCoordinate();
void on_titleControls_clicked();
void on_controlsStart_clicked();
void playerShoot();

};

#endif // MAINWINDOW_H
