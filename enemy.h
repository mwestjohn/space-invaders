#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>

class enemy
{
public:
    enemy();
    int enemyX;
    int enemyY;

    QPixmap* enemySprite;
    QPixmap* enemyBullet;

};

#endif // ENEMY_H
