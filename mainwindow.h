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
    bool gameStart=0;

private:
    Ui::MainWindow *ui;
    QPixmap* background;
    player* player_one;
    int direction =0;

protected:
void paintEvent(QPaintEvent *e);
void keyPressEvent(QKeyEvent *evt);



private slots:
void on_titleStart_clicked();
void updateCoordinate();
void on_titleControls_clicked();
void on_controlsStart_clicked();
};

#endif // MAINWINDOW_H
