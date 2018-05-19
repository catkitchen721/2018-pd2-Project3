#include "bullet.h"


Bullet::Bullet()
{
    this->speed = 12;
    this->inclination = 1.5;
}

void Bullet::fly()
{
    setPos(x(), y() - this->speed);
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::flyL()
{
    setPos(x() - ((float)this->speed / this->inclination), y() - (this->speed * sqrt(this->inclination * this->inclination - 1) / this->inclination));
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::flyR()
{
    setPos(x() + ((float)this->speed / this->inclination), y() - (this->speed * sqrt(this->inclination * this->inclination - 1) / this->inclination));
    if(y() < 0 || x() < 0 || x() > this->scene()->width()) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::setBullet(int mode, Minion *minion)
{
    if(qrand() % 2 == 0) {
        this->setPixmap(QPixmap(":/resource/black_bullet.png").scaled(20, 20));
    }
    else {
        this->setPixmap(QPixmap(":/resource/red_bullet.png").scaled(20, 20));
    }
    this->setPos(minion->x() + minion->pixmap().width() / 2 - this->pixmap().width() / 2, minion->y() - this->pixmap().height());

    if(mode == 0)
    {
        this->connect(minion->t, SIGNAL(timeout()), this, SLOT(fly()));
    }
    if(mode == 1)
    {
        this->connect(minion->t, SIGNAL(timeout()), this, SLOT(flyL()));
    }
    if(mode == 2)
    {
        this->connect(minion->t, SIGNAL(timeout()), this, SLOT(flyR()));
    }

    minion->scene()->addItem(static_cast<QGraphicsPixmapItem*>(this));
}
