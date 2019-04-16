#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>



class player
{
public:
    player();
    QPixmap* playerSprite;
    QPixmap* bullet;
    int playerX = 300;
    int playerY = 550;
    int bulletX;
    int bulletY = 550;
    QPixmap* getSprite();





};

#endif // PLAYER_H
