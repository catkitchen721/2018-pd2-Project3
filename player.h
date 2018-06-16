#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "minion.h"

class Player : public Minion
{
public:
    Player();
    virtual void forwardMoving();
    virtual void leftMoving();
    virtual void rightMoving();
    virtual void backwardMoving();
    virtual void shooting();

public slots:
    virtual void checkHit();

private:
    QMediaPlayer *shootingSound;
    QMediaPlaylist *playlist;
};

#endif // PLAYER_H
