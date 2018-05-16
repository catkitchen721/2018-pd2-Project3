#include "bullet.h"

bullet::bullet()
{
    this->speed = 10;
}

void bullet::fly()
{
    setPos(x(), y() - this->speed);
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::flyL()
{
    setPos(x() - (this->speed / 2), y() - (this->speed * sqrt(3.0) / 2));
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::flyR()
{
    setPos(x() + (this->speed / 2), y() - (this->speed * sqrt(3.0) / 2));
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}
