#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>



class player
{
public:
    player();
    int playerX = 300;
    int playerY = 550;
    int bulletX;
    int bulletY = 550;
    QPixmap* getSprite();

private:
    QPixmap* playerSprite;
    QPixmap* bullet;



};

#endif // PLAYER_H
