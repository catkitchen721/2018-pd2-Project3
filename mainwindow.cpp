#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1201, 871)),
    player(new Player),
    timer(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player->setPixmap(QPixmap(":/res/reimu.jpg"));
    scene->addItem(static_cast<QGraphicsPixmapItem *>(player));
    player->setPos(0, 0);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(!e->isAutoRepeat())
        {
            player->isforwardMoving = true;
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(!e->isAutoRepeat())
        {
            player->isbackwardMoving = true;
        }
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(!e->isAutoRepeat())
        {
            player->isleftMoving = true;
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(!e->isAutoRepeat())
        {
            player->isrightMoving = true;
        }
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(!e->isAutoRepeat())
        {
            player->isforwardMoving = false;
        }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(!e->isAutoRepeat())
        {
            player->isbackwardMoving = false;
        }
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(!e->isAutoRepeat())
        {
            player->isleftMoving = false;
        }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(!e->isAutoRepeat())
        {
            player->isrightMoving = false;
        }
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    bullet *b[3];
    b[0] = new bullet;
    b[1] = new bullet;
    b[2] = new bullet;

    if(qrand() % 2 == 0) {
        b[0]->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
        b[1]->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
        b[2]->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
    }
    else {
        b[0]->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
        b[1]->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
        b[2]->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
    }
    b[0]->setPos(player->x() + player->pixmap().width() / 2 - b[0]->pixmap().width() / 2, player->y() - b[0]->pixmap().height());
    b[1]->setPos(player->x() + player->pixmap().width() / 2 - b[1]->pixmap().width() / 2, player->y() - b[1]->pixmap().height());
    b[2]->setPos(player->x() + player->pixmap().width() / 2 - b[2]->pixmap().width() / 2, player->y() - b[2]->pixmap().height());
    b[0]->connect(timer, SIGNAL(timeout()), b[0], SLOT(fly()));
    b[1]->connect(timer, SIGNAL(timeout()), b[1], SLOT(flyL()));
    b[2]->connect(timer, SIGNAL(timeout()), b[2], SLOT(flyR()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b[0]));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b[1]));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b[2]));
}


































