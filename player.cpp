#include "player.h"


player::player()
{
    playerSprite = new QPixmap(":/sprites/download.jpg");
    bullet = new QPixmap(":/.png");


}

QPixmap* player::getSprite(){
    return playerSprite;
}



