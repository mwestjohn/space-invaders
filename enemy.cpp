#include "enemy.h"

enemy::enemy()
{
    enemySprite1 = new QPixmap(":/sprites/images.png");
    enemySprite2 = new QPixmap(":/sprites/goomba-transparent-pixel-1.png");
    enemySprite3 = new QPixmap("qrc:/sprites/OctoRock-1.png (1).png");
    enemyBullet = new QPixmap(":/.png");

}
