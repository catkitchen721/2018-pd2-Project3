#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 800, 600)),
    player(new Player),
    timer(new QTimer),
    bgm(new QMediaPlayer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    scene->addPixmap(QPixmap(":/pic/resource/bg.jpeg").scaled(800, 1200));
    scene->setSceneRect(0, 0, 800, 600);
    player->setPixmap(QPixmap(":/pic/resource/player.png").scaled(64, 64));
    scene->addItem(static_cast<QGraphicsPixmapItem *>(player));
    player->setPos(350, 550);

    bgm->setMedia(QMediaContent(QUrl("qrc:/audio/resource/bgm.mp3")));
    bgm->setVolume(50);
    bgm->play();
    timer->start(10);

    //countTime = 0;
    //connect(timer, SIGNAL(timeout()), this, SLOT(backgroundMoving()));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    enemy = new Enemy;
    scene->addItem(static_cast<QGraphicsPixmapItem *>(enemy));
    enemy->setPixmap(QPixmap(":/pic/resource/player.png").scaled(64, 64));
    enemy->setPos(350, 50);

    enemyMovingFreq = new QTimer();
    enemyMovingFreq->start(2000);

    enemy->isbackwardMoving = false;
    enemy->isshooting = true;

    connect(enemyMovingFreq, SIGNAL(timeout()), this, SLOT(enemyMovingByAI()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::backgroundMoving()
{
    if(countTime == 600)
    {
        scene->setSceneRect(0, 600 - countTime * 1, 800, 600);
        countTime = 0;
    }
    else
    {
        scene->setSceneRect(0, 600 - countTime * 1, 800, 600);
        ++countTime;
    }
}

void MainWindow::enemyMovingByAI()
{
    if(!enemy->isforwardMoving && !enemy->isbackwardMoving && !enemy->isrightMoving && !enemy->isleftMoving)
    {
        directionChoose = qrand() % 4;
    }

    switch(directionChoose)
    {
    case 0:
        if(!enemy->isforwardMoving) enemy->isforwardMoving = true;
        else enemy->isforwardMoving = false;
        break;
    case 1:
        if(!enemy->isbackwardMoving) enemy->isbackwardMoving = true;
        else enemy->isbackwardMoving = false;
        break;
    case 2:
        if(!enemy->isrightMoving) enemy->isrightMoving = true;
        else enemy->isrightMoving = false;
        break;
    case 3:
        if(!enemy->isleftMoving) enemy->isleftMoving = true;
        else enemy->isleftMoving = false;
        break;
    }
    if(!enemy->isshooting) enemy->isshooting = true;
    else enemy->isshooting = false;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(player->isinitialing == true) return;

    switch(e->key()) {

    case Qt::Key_W:
        if(!e->isAutoRepeat())
        {
            player->isforwardMoving = true;
        }
        break;

    case Qt::Key_S:
        if(!e->isAutoRepeat())
        {
            player->isbackwardMoving = true;
        }
        break;

    case Qt::Key_A:
        if(!e->isAutoRepeat())
        {
            player->isleftMoving = true;
        }
        break;

    case Qt::Key_D:
        if(!e->isAutoRepeat())
        {
            player->isrightMoving = true;
        }
        break;

    case Qt::Key_J:
        if(!e->isAutoRepeat())
        {
            player->isshooting = true;
        }
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(player->isinitialing == true) return;

    switch(e->key()) {

    case Qt::Key_W:
        if(!e->isAutoRepeat())
        {
            player->isforwardMoving = false;
        }
        break;

    case Qt::Key_S:
        if(!e->isAutoRepeat())
        {
            player->isbackwardMoving = false;
        }
        break;

    case Qt::Key_A:
        if(!e->isAutoRepeat())
        {
            player->isleftMoving = false;
        }
        break;

    case Qt::Key_D:
        if(!e->isAutoRepeat())
        {
            player->isrightMoving = false;
        }
        break;

    case Qt::Key_J:
        if(!e->isAutoRepeat())
        {
            player->isshooting = false;
        }
        break;
    }
}
