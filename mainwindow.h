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

private:
    Ui::MainWindow *ui;
    QPixmap* background;
    player* player_one;
    int direction;

protected:
void paintEvent(QPaintEvent *e);
void keyPressEvent(QKeyEvent *evt);
void updateCoordinate();


};

#endif // MAINWINDOW_H
