#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1000, 1000)),
    player(new Player),
    timer(new QTimer),
    bgm(new QMediaPlayer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player->setPixmap(QPixmap(":/pic/resource/player.png"));
    scene->addItem(static_cast<QGraphicsPixmapItem *>(player));
    player->setPos(0, 0);

    bgm->setMedia(QMediaContent(QUrl("qrc:/audio/resource/bgm.mp3")));
    bgm->setVolume(50);
    bgm->play();
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
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
