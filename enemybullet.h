#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "bullet.h"

class EnemyBullet : public Bullet
{
public:
    EnemyBullet();
    virtual void setBullet(int mode, Minion *minion);

public slots:
    virtual void fly();
    virtual void flyL();
    virtual void flyR();
};

#endif // ENEMYBULLET_H
