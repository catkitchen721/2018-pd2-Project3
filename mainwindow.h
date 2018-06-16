#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>

#include "bullet.h"
#include "player.h"
#include "enemy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);

    void backgroundMoving();
    void enemyMovingByAI();
    void updateLCD();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *player;
    Enemy *enemy;
    QTimer *timer;
    QTimer *enemyMovingFreq;
    QMediaPlayer *bgm;
    QMediaPlaylist *bgmPlaylist;
    int countTime;
    int directionChoose;
    int isWin;
};

#endif // MAINWINDOW_H
