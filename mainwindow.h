#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "player.h"
#include "enemy.h"
#include "fort.h"
#include <QPaintEvent>
#include <QKeyEvent>
#include <iostream>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QString>
#include <QTime>
#include <QLabel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void bulletSound();
    void spawnEnemies();
    void moveEnemies();
    void resetEnemies();
    void startGame();
    void generateSpecial();
    void createForts();
    void checkPlayerBulletCollisionEnemy();
    void checkPlayerBulletCollisionSpecial();
    void checkPlayerBulletCollisionFort();

private:
    Ui::MainWindow *ui;
    QPixmap* background;
    player* player_one;
    enemy* enemy_arr[11][5];
    int direction =0;
    QTimer *enemyTimer;
    QTimer *bulletTimer;
    QTimer* specialTimer;
    bool gameStart=0;
    bool shoot=0;
    bool spawnSpecial;
    bool specialIsSpawned;
    QMediaPlayer* media = new QMediaPlayer();
    QMediaPlaylist* playlist = new QMediaPlaylist;
    QMediaPlayer* bg_music;
    int x = 50;
    int y = 50;
    int score;
    int enemies_left;
    int enemy_speed;
    int lives;
    enemy* bonus_enemy;
    QLabel *scoreLabel;
    fort* bunker[4][8];
    int specialDirection;

protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *evt);

private slots:
    void on_titleStart_clicked();
    void updateCoordinate();
    void on_titleControls_clicked();
    void on_controlsStart_clicked();
    void playerShoot();
    void on_overStart_clicked();
    void on_overTitle_clicked();
    void specialMove();
};

#endif // MAINWINDOW_H
