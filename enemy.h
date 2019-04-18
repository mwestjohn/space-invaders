#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>

class enemy
{
public:
    enemy();
    int enemyX;
    int enemyY;

    QPixmap* enemySprite1;
        QPixmap* enemySprite2;
            QPixmap* enemySprite3;
    QPixmap* enemyBullet;

};

#endif // ENEMY_H
