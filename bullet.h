#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <cmath>

#include "player.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    void setBullet(int mode, Minion *minion);

public slots:
    void fly();
    void flyL();
    void flyR();

private:
    int speed;
    float inclination;
};

#endif // BULLET_H
