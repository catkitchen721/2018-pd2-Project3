#include "minion.h"

Minion::Minion() :
    isforwardMoving(false), isleftMoving(false), isrightMoving(false), isbackwardMoving(false), isshooting(false),
    t(new QTimer), tBullet(new QTimer)
{
    connect(t, SIGNAL(timeout()), this, SLOT(forwardMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(leftMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(rightMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(backwardMoving()));
    connect(tBullet, SIGNAL(timeout()), this, SLOT(shooting()));
}

void Minion::setSpeed(int speed)
{
    this->speed = speed;
}

int Minion::getSpeed()
{
    return this->speed;
}
