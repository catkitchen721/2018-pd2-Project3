#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    bool isforwardMoving;
    bool isleftMoving;
    bool isrightMoving;
    bool isbackwardMoving;

private slots:
    void forwardMoving();
    void leftMoving();
    void rightMoving();
    void backwardMoving();

private:
    QTimer *t;
    int speed;
};

#endif // PLAYER_H
