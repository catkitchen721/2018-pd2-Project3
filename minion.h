#ifndef MINION_H
#define MINION_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Minion : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Minion();
    bool isforwardMoving;
    bool isleftMoving;
    bool isrightMoving;
    bool isbackwardMoving;
    bool isshooting;
    QTimer *t;
    QTimer *tBullet;

    void setSpeed(int speed);
    int getSpeed();
    friend class bullet;

private slots:
    virtual void forwardMoving() = 0;
    virtual void leftMoving() = 0;
    virtual void rightMoving() = 0;
    virtual void backwardMoving() = 0;
    virtual void shooting() = 0;

private:
    int speed;
};

#endif // MINION_H
