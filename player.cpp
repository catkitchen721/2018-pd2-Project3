#include "player.h"

Player::Player() :
    isforwardMoving(false), isleftMoving(false), isrightMoving(false), isbackwardMoving(false),
    t(new QTimer)
{
    t->start(10);

    this->speed = 5;

    connect(t, SIGNAL(timeout()), this, SLOT(forwardMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(leftMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(rightMoving()));
    connect(t, SIGNAL(timeout()), this, SLOT(backwardMoving()));
}

void Player::forwardMoving()
{
    if(isforwardMoving && (this->y() > 0))
    {
        this->setPos(this->x(), this->y() - this->speed);
    }
}

void Player::leftMoving()
{
    if(isleftMoving && (this->x() > 0))
    {
        this->setPos(this->x() - this->speed, this->y());
    }
}

void Player::rightMoving()
{
    if(isrightMoving && (this->x() < this->scene()->width() - this->pixmap().width()))
    {
        this->setPos(this->x() + this->speed, this->y());
    }
}

void Player::backwardMoving()
{
    if(isbackwardMoving && (this->y() < this->scene()->height() - this->pixmap().height()))
    {
        this->setPos(this->x(), this->y() + this->speed);
    }
}
