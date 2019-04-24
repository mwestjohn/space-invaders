#ifndef FORT_H
#define FORT_H

#include <QRect>

class fort
{
public:
    fort();
    fort(int x, int y, int width, int height);
    int getX();
    int getY();
    int getDamage();
    void setDamage(int new_damage);
    QRect* getblock();
    bool getStatus();
    void setStatus(bool new_status);

private:
    QRect* block;
    int x_pos;
    int y_pos;
    int damage;
    bool isAlive;
};

#endif // FORT_H
