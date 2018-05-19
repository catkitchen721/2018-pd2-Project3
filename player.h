#ifndef PLAYER_H
#define PLAYER_H

#include "minion.h"

class Player : public Minion
{
public:
    Player();
    virtual void forwardMoving();
    virtual void leftMoving();
    virtual void rightMoving();
    virtual void backwardMoving();
    virtual void shooting();
};

#endif // PLAYER_H
