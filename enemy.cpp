#include "enemy.h"

enemy::enemy()
{
    enemySprite = new QPixmap(":/sprites/goomba.png");
    enemyBullet = new QPixmap(":/.png");
}

enemy::enemy(int x, int y, QPixmap* sprite, QPixmap* bullet, int score_worth, bool dead) {
    enemyX = x;
    enemyY = y;
    enemySprite = new QPixmap(*sprite);
    enemyBullet = new QPixmap(*bullet);
    score = score_worth;
    isDead = dead;
}

int enemy::getX() {
    return enemyX;
}

int enemy::getY() {
    return enemyY;
}

int enemy::getScore() {
    return score;
}

QPixmap* enemy::getSprite() {
    return enemySprite;
}

QPixmap* enemy::getBullet() {
    return enemyBullet;
}

void enemy::setX(int x) {
    enemyX = x;
}

void enemy::setY(int y) {
    enemyY = y;
}

bool enemy::getStatus() {
    return isDead;
}

void enemy::setStatus(bool status){
    isDead = status;
}
