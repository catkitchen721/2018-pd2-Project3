#include "bullet.h"

bullet::bullet()
{

}

void bullet::fly()
{
    setPos(x(), y() - 3);
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::flyL()
{
    setPos(x() - 3, y() - 3);
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::flyR()
{
    setPos(x() + 3, y() - 3);
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}
