#ifndef ENEMY_H
#define ENEMY_H

#include "minion.h"

class Enemy : public Minion
{
public:
    Enemy();
    virtual void forwardMoving();
    virtual void leftMoving();
    virtual void rightMoving();
    virtual void backwardMoving();
    virtual void shooting();

public slots:
    virtual void checkHit();

};

#endif // ENEMY_H
