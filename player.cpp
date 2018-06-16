#include "player.h"
#include "bullet.h"
#include "enemybullet.h"

Player::Player() : Minion(), shootingSound(new QMediaPlayer), playlist(new QMediaPlaylist)
{
    tBullet->start(80);

    playlist->addMedia(QUrl("qrc:/audio/resource/shoot.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    shootingSound->setMedia(playlist);
    shootingSound->setVolume(60);

    isinitialing = true;
    this->setSpeed(3);
    isforwardMoving = true;
    t->start(50);
    t->singleShot(800, this, SLOT(stopInitialGo()));

    this->setHP(3);
    connect(t, SIGNAL(timeout()), this, SLOT(checkHit()));
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
    if(isforwardMoving && isleftMoving && (this->x() > 100))
    {
        this->setPos(this->x() - this->getSpeed()/sqrt(2), this->y());
    }
    else if(isleftMoving && (this->x() > 100))
    {
        this->setPos(this->x() - this->getSpeed(), this->y());
    }
}

void Player::rightMoving()
{ 
    if(isforwardMoving && isrightMoving && (this->x() < this->scene()->width() - 100 - this->pixmap().width()))
    {
        this->setPos(this->x() + this->getSpeed()/sqrt(2), this->y());
    }
    else if(isrightMoving && (this->x() < this->scene()->width() - 100 - this->pixmap().width()))
    {
        this->setPos(this->x() + this->getSpeed(), this->y());
    }
}

void Player::backwardMoving()
{
    if(isbackwardMoving && isleftMoving && (this->y() < this->scene()->height() - this->pixmap().height()))
    {
        this->setPos(this->x(), this->y() + this->getSpeed()/sqrt(2));
    }
    else if(isbackwardMoving && isrightMoving && (this->y() < this->scene()->height() - this->pixmap().height()))
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

        if(shootingSound->state() == QMediaPlayer::StoppedState)
        {
            shootingSound->play();
        }
    }
    else
    {
        if(shootingSound->state() == QMediaPlayer::PlayingState)
        {
            shootingSound->stop();
        }
    }
}

void Player::checkHit()
{
    QList<QGraphicsItem *> colliders = this->collidingItems();
    qDebug() << this->hp << endl;
    for(int i=0; i<colliders.size(); ++i)
    {
        if(typeid(*(colliders[i])) == typeid(EnemyBullet))
        {
            this->isHit(1);
            delete colliders[i];
            qDebug() << this->hp << endl;
        }
    }
}
