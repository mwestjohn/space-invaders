#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>

class enemy
{
public:
    enemy();
    enemy(int x, int y, QPixmap* sprite, QPixmap* bullet, int score_worth);
    int getX();
    int getY();
    int getScore();
    void setX(int x);
    void setY(int y);
    QPixmap* getSprite();
    QPixmap* getBullet();
    void setPixmap(QPixmap* sprite);

private:
    int enemyX;
    int enemyY;
    QPixmap* enemySprite;
    QPixmap* enemyBullet;
    int score;
};

#endif // ENEMY_H
