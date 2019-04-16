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
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if(gameStart==1){
         painter.drawPixmap(0,0,800,600,*background);

         painter.drawPixmap(player_one->playerX,player_one->playerY,50,50,*(player_one->getSprite()));
         update();
}

}

void MainWindow::keyPressEvent(QKeyEvent *evt)
{
    if(gameStart==1){
    if ((evt->key()==Qt::Key_Left || evt->key()==Qt::Key_A)) {
        direction=1;
        qDebug()<< "left";

    } else if ((evt->key()==Qt::Key_Right || evt->key()==Qt::Key_D)) {
        direction=2;
        qDebug()<< "right";
           } else if ((evt->key()==Qt::Key_Space)){
        qDebug()<<"Shoot";
    }

}
}
void MainWindow::updateCoordinate()
{


    if(direction==1 && player_one->playerX>0){ player_one->playerX-= 10; direction=0;}
    if(direction==2 && player_one->playerX<750){ player_one->playerX+= 10; direction=0;}


    }


void MainWindow::on_titleStart_clicked()
{
    gameStart = 1;
    ui->stackedWidget->setCurrentIndex(2);
    timer->start(50);
}

void MainWindow::on_titleControls_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_controlsStart_clicked()
{
    gameStart = 1;
    ui->stackedWidget->setCurrentIndex(2);
    timer->start(50);
}
