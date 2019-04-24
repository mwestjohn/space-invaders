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
    background = new QPixmap(":/sprites/galagaship.png");
    player_one = new player();
    score = 0;
    enemies_left = 0;

    enemyTimer = new QTimer(this);
    bulletTimer = new QTimer(this);
    connect(enemyTimer,SIGNAL(timeout()),this,SLOT(updateCoordinate()));
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(playerShoot()));

    setWindowTitle("Retro Game Invaders");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete enemyTimer;
    delete bulletTimer;
    delete media;
}

void MainWindow::bulletSound()
{
    media->setMedia(QUrl("qrc:/sounds/ka-chow.mp3"));
//    media->setMedia(QUrl("qrc:/sounds/taughthimthat.mp3"));
    if(shoot==1){
        media->play();
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.setBrush(Qt::green);
    if(gameStart==1){
        painter.drawPixmap(player_one->playerX,player_one->playerY,35,50,*(player_one->getSprite()));
        for(int i = 0 ; i < 11 ; i++) {
            for(int j = 0 ; j < 5 ; j++){
                if(!(enemy_arr[i][j]->getStatus())){
                    painter.drawPixmap(enemy_arr[i][j]->getX(),enemy_arr[i][j]->getY(),25,25,*(enemy_arr[i][j]->getSprite()));
                }
            }
        }
        if(shoot==1){
            painter.drawEllipse(player_one->bulletX+20,player_one->bulletY,10,10);
        }
    }
}//end paintEvent

void MainWindow::keyPressEvent(QKeyEvent *evt)
{
    if(gameStart==1){
        if ((evt->key()==Qt::Key_Left || evt->key()==Qt::Key_A)) {
            if(player_one->playerX > 0){
                player_one->playerX -= 5;
            }
        } else if ((evt->key()==Qt::Key_Right || evt->key()==Qt::Key_D)) {
            if(player_one->playerX <= 750) {
                player_one->playerX += 5;
            }
        }
        else if ((evt->key()==Qt::Key_Space)){
            if(shoot==0){
                shoot =1;
                player_one->bulletX=player_one->playerX;
                player_one->bulletY=player_one->playerY;
                bulletSound();
            }
        }
    }
    update();
} // end keyPressEvent

void MainWindow::updateCoordinate()
{
    moveEnemies();
    if(gameStart == 0) {
        bulletTimer->stop();
        enemyTimer->stop();
        ui->stackedWidget->setCurrentIndex(3);
        QLabel *scoreLabel = new QLabel();
        scoreLabel = findChild<QLabel*>("score");
        QString scoreString = QString::number(score);
        scoreString = "You Scored: " + scoreString;
        qDebug() << scoreLabel->text();
        scoreLabel->setText(scoreString);
    } else {
        update();
    }
} // end updateCoordinates

void MainWindow::playerShoot()
{
    if(shoot==1){
        if(player_one->bulletY>0){
            player_one->bulletY-=20;
            for(int j = 4 ; j >= 0 ; j--) {
                for(int i = 0 ; i < 11 ; i++) {
                    if(player_one->bulletX >= enemy_arr[i][j]->getX() && player_one->bulletX <= enemy_arr[i][j]->getX()+25
                            && player_one->bulletY <= (enemy_arr[i][j]->getY()+25) && player_one->bulletY >= enemy_arr[i][j]->getY()
                            && !(enemy_arr[i][j]->getStatus())) {
                        score += enemy_arr[i][j]->getScore();
                        enemy_arr[i][j]->setStatus(true);
                        enemies_left--;
                        enemy_speed -= 10;
                        enemyTimer->start(enemy_speed);
                        shoot = 0;
                    }
                }
            }
        } else {
            shoot=0;
        }
        if(enemies_left == 0){
            resetEnemies();
        }
        update();
    }
}

void MainWindow::startGame() {
    enemy_speed = 1000;
    gameStart = 1;
    ui->stackedWidget->setCurrentIndex(2);
    enemyTimer->start(enemy_speed);
    bulletTimer->start(25);
    spawnEnemies();
    enemies_left = 55;
}

void MainWindow::on_titleStart_clicked()
{
    startGame();
}

void MainWindow::on_titleControls_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_controlsStart_clicked()
{
    startGame();
}

void MainWindow::on_overStart_clicked()
{
    startGame();
}

void MainWindow::on_overTitle_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::spawnEnemies(){
    int enemy_y = 0;
    int enemy_x = 50;
    QPixmap* enemy_sprite = new QPixmap(/*":/sprites/goomba.png"*/);
    QPixmap* bullet = new QPixmap(":/sprites/bullet.png");
    int score = 20;
    for(int i = 0 ; i < 11 ; i++) {
        enemy_x = 50 + (25 * i);
        for(int j = 0 ; j < 5 ; j++) {
            enemy_y = 50 + (j * 25);
            if(j == 0) {
                enemy_sprite->load(":/sprites/bee.png");
                score = 50;
            } else if(j == 1 || j == 2) {
                enemy_sprite->load(":/sprites/OctoRock.png");
                score = 35;
            } else {
                enemy_sprite->load(":/sprites/goomba.png");
                score = 20;
            }
            enemy_arr[i][j] = new enemy(enemy_x,enemy_y,enemy_sprite,bullet,score, false);
        }
    }
}

void MainWindow::resetEnemies() {
    for(int i = 0 ; i < 11 ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            enemy_arr[i][j]->setX((50 + (i * 25)));
            enemy_arr[i][j]->setY((50 + (j * 25)));
            enemy_arr[i][j]->setStatus(false);
        }
    }
    enemies_left = 55;
    enemy_speed = 1000;
}

void MainWindow::moveEnemies(){
    bool move_down = false;
    if(direction == 0){
        for(int i = 10 ; i >= 0 ; i--) {
            for(int j = 0 ; j < 5 ; j++) {
                if((enemy_arr[i][j]->getX()+25) >= this->width() && !(enemy_arr[i][j]->getStatus())) {
                    move_down = true;
                }
                if((enemy_arr[i][j]->getY()+25) >= 450 && !(enemy_arr[i][j]->getStatus())) {
                    gameStart = 0;
                }
            }
            if(move_down == true) {
                break;
            }
        }
        for(int i = 0 ; i <= 10 ; i++) {
            for(int j = 0 ; j < 5 ; j++) {
                if(move_down) {
                    enemy_arr[i][j]->setY((enemy_arr[i][j]->getY()+25));
                    direction = 1;
                } else {
                    enemy_arr[i][j]->setX((enemy_arr[i][j]->getX()+25));
                }
            }
        }
    } else if(direction == 1) {
        for(int i = 0 ; i <= 10 ; i++) {
            for(int j = 0 ; j < 5 ; j++) {
                if(enemy_arr[i][j]->getX() <= 0 && !(enemy_arr[i][j]->getStatus())) {
                    move_down = true;
                }
            }
            if(move_down == true) {
                break;
            }
        }
        for(int i = 0 ; i <= 10 ; i++) {
            for(int j = 0 ; j < 5 ; j++) {
                if(move_down) {
                    enemy_arr[i][j]->setY((enemy_arr[i][j]->getY()+25));
                    direction = 0;
                } else {
                    enemy_arr[i][j]->setX((enemy_arr[i][j]->getX()-25));
                }
            }
        }
    }
}


