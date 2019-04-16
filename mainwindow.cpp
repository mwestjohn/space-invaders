#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    setFixedSize(800,600);
    background = new QPixmap(":/sprites/download.jpg");
    player_one = new player();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateCoordinate()));

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

         painter.drawPixmap(0,0,800,600,*background);

         painter.drawPixmap(player_one->playerX,player_one->playerY,50,50,*(player_one->getSprite()));


}

void MainWindow::keyPressEvent(QKeyEvent *evt)
{

    if ((evt->key()==Qt::Key_Left || evt->key()==Qt::Key_A) && direction != 4 ) {
        direction=1;
        qDebug()<< "left";

    } else if ((evt->key()==Qt::Key_Right || evt->key()==Qt::Key_D) && direction != 3 ) {
        direction=2;
        qDebug()<< "right";
           }

}
void MainWindow::updateCoordinate()
{


    if(direction==1) player_one->playerX-= 10;
    if(direction==2) player_one->playerX+= 10;

    }
