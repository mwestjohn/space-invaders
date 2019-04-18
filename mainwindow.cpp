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
    enemy_one = new enemy();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateCoordinate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(playerShoot()));

   }



MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete media;

}

void MainWindow::bulletSound()
{

       media->setMedia(QUrl("qrc:/sounds/ka-chow.mp3"));
//        media->setMedia(QUrl("qrc:/sounds/taughthimthat.mp3"));

        if(shoot==1){  media->play();}

}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if(gameStart==1){
         painter.drawPixmap(0,0,800,600,*background);


         painter.drawPixmap(player_one->playerX,player_one->playerY,50,50,*(player_one->getSprite()));
         update();



         for (int i = 0; i < 5;i++)
         {for (int j = 0; j < 12;j++){

             painter.setBrush(Qt::green);
             painter.drawPixmap(x,y,50,50,*(enemy_one->enemySprite2));
             x+=35;

         }
             x=50;
             y+=35;
         }
                x = 50;
                y = 50;


         if(shoot==1){painter.drawEllipse(player_one->bulletX+20,player_one->bulletY,10,10);

}
}


}//end qPaint event

void MainWindow::keyPressEvent(QKeyEvent *evt)
{
    if(gameStart==1){
    if ((evt->key()==Qt::Key_Left || evt->key()==Qt::Key_A)) {
        direction=1;
        qDebug()<< "left";

    } else if ((evt->key()==Qt::Key_Right || evt->key()==Qt::Key_D)) {
        direction=2;
        qDebug()<< "right";
           }
    else if ((evt->key()==Qt::Key_Space)){
        if(shoot==0){
            qDebug()<<"Shoot";
        shoot =1;
        player_one->bulletX=player_one->playerX;
        player_one->bulletY=player_one->playerY;
        bulletSound();
}
    }

}
}
void MainWindow::updateCoordinate()
{


    if(direction==1 && player_one->playerX>0){ player_one->playerX-= 10; direction=0;}
    if(direction==2 && player_one->playerX<750){ player_one->playerX+= 10; direction=0;}


    }

void MainWindow::playerShoot()
{     if(shoot==1){

        if(player_one->bulletY>0){player_one->bulletY-=20;}
        else {shoot=0;}
    update();

}
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
