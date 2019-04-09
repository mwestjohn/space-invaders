#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,600);
    background = new QPixmap(":/.png");
    player = new QPixmap(":/.png");
    bullet = new QPixmap(":/.png");
    enemy = new QPixmap(":/.png");
    enemyBullet = new QPixmap(":/.png");


}

MainWindow::~MainWindow()
{
    delete ui;
}
