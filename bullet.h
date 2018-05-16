#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    bool isShooting;

public slots:
    void fly();
    void flyL();
    void flyR();

private:
    int speed;
};

#endif // BULLET_H
