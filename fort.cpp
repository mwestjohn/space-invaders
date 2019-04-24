#include "fort.h"

fort::fort()
{

}

fort::fort(int x, int y, int width, int height) {
    x_pos = x;
    y_pos = y;
    damage = 3;
    isAlive = true;
    block = new QRect(x,y,width,height);
}

void fort::setDamage(int new_damage) {
    damage = new_damage;
}

int fort::getX() {
    return x_pos;
}

int fort::getY() {
    return y_pos;
}

int fort::getDamage() {
    return damage;
}

QRect* fort::getblock() {
    return block;
}

bool fort::getStatus() {
    return isAlive;
}
