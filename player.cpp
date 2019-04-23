#include "player.h"


player::player()
{
    playerSprite = new QPixmap(":/sprites/galagaship.png");
    bullet = new QPixmap(":/.png");
}

QPixmap* player::getSprite(){
    return playerSprite;
}



