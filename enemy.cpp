#include "enemy.h"

enemy::enemy()
{
    enemySprite = new QPixmap(":/sprites/images.png");
    enemyBullet = new QPixmap(":/.png");

}

enemy::enemy(int x, int y, QPixmap* sprite, QPixmap* bullet, int score_worth) {
    enemyX = x;
    enemyY = y;
    enemySprite = sprite;
    enemyBullet = bullet;
    score = score_worth;
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
\
QPixmap* enemy::getSprite() {
    return enemySprite;
}

QPixmap* enemy::getBullet() {
    return enemyBullet;
}

void enemy::setPixmap(QPixmap* sprite) {
    enemySprite = sprite;
}

void enemy::setX(int x) {
    enemyX = x;
}

void enemy::setY(int y) {
    enemyY = y;
}
