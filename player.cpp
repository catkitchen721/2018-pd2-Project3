#include "player.h"
#include "bullet.h"

Player::Player() : Minion()
{
    t->start(10);
    tBullet->start(80);

    this->setSpeed(5);
}

void Player::forwardMoving()
{

    if(isforwardMoving && isleftMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() - this->getSpeed()/sqrt(2));
    }
    else if(isforwardMoving && isrightMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() - this->getSpeed()/sqrt(2));
    }
    else if(isforwardMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() - this->getSpeed());
    }
}

void Player::leftMoving()
{
    if(isforwardMoving && isleftMoving && (this->y() > 0))
    {
        this->setPos(this->x() - this->getSpeed()/sqrt(2), this->y());
    }
    else if(isleftMoving && (this->x() > 0))
    {
        this->setPos(this->x() - this->getSpeed(), this->y());
    }
}

void Player::rightMoving()
{ 
    if(isforwardMoving && isrightMoving && (this->y() > 0))
    {
        this->setPos(this->x() + this->getSpeed()/sqrt(2), this->y());
    }
    else if(isrightMoving && (this->x() < this->scene()->width() - this->pixmap().width()))
    {
        this->setPos(this->x() + this->getSpeed(), this->y());
    }
}

void Player::backwardMoving()
{
    if(isbackwardMoving && isleftMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() + this->getSpeed()/sqrt(2));
    }
    else if(isbackwardMoving && isrightMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() + this->getSpeed()/sqrt(2));
    }
    else if(isbackwardMoving && (this->y() < this->scene()->height() - this->pixmap().height()))
    {
        this->setPos(this->x(), this->y() + this->getSpeed());
    }
}

void Player::shooting()
{
    if(isshooting)
    {
        Bullet *b[3];
        b[0] = new Bullet;
        b[1] = new Bullet;
        b[2] = new Bullet;

        b[0]->setBullet(0, this);
        b[1]->setBullet(1, this);
        b[2]->setBullet(2, this);
    }
}
