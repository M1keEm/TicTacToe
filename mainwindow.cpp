#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPlayer=1;
    for(int i=0;i<9;i++){
        data_tab[i] = 0;
    }
    QObject::connect(ui->P1, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P2, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P3, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P4, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P5, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P6, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P7, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P8, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->P9, SIGNAL(clicked()), SLOT(clicked()));
    QObject::connect(ui->newGame, SIGNAL(clicked()), this, SLOT(newGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clicked()
{
    QObject* button = QObject::sender();
    QString help = button->objectName();
    QString name = help;
    help.remove("P");
    int index = help.toInt();
    if(data_tab[index-1]==0){
        QString iconPath;
        QString pixmapPath;
        if (currentPlayer == 1) {
            iconPath = ":/img/img/x.bmp";
            pixmapPath = ":/img/img/osmall.bmp";
            data_tab[index-1] = currentPlayer;
            currentPlayer = 2;
        } else {
            iconPath = ":/img/img/o.bmp";
            pixmapPath = ":/img/img/xsmall.bmp";
            data_tab[index-1] = currentPlayer;
            currentPlayer = 1;
        }

        QIcon icon(iconPath);
        QPixmap pixmap(pixmapPath);
        if(name == "P1"){
            ui->P1->setIcon(icon);
        }else if(name == "P2"){
            ui->P2->setIcon(icon);
        }else if(name == "P2"){
            ui->P2->setIcon(icon);
        }else if(name == "P3"){
            ui->P3->setIcon(icon);
        }else if(name == "P4"){
            ui->P4->setIcon(icon);
        }else if(name == "P5"){
            ui->P5->setIcon(icon);
        }else if(name == "P6"){
            ui->P6->setIcon(icon);
        }else if(name == "P7"){
            ui->P7->setIcon(icon);
        }else if(name == "P8"){
            ui->P8->setIcon(icon);
        }else{
            ui->P9->setIcon(icon);
        }
        if(isWin()==1){
            QString winInfo;
            if(currentPlayer == 1){
                winInfo = "Gracz 2 wygrywa!";
            }else{
                winInfo = "Gracz 1 wygrywa!";
            }
            QMessageBox::information(this, "Koniec Gry ", winInfo);
            newGame();
        }
        ui->playerIcon->setPixmap(pixmap);
    }

}

void MainWindow::newGame()
{
    QIcon voidIcon(":/img/img/nic.bmp");
    ui->P1->setIcon(voidIcon);
    ui->P2->setIcon(voidIcon);
    ui->P3->setIcon(voidIcon);
    ui->P4->setIcon(voidIcon);
    ui->P5->setIcon(voidIcon);
    ui->P6->setIcon(voidIcon);
    ui->P7->setIcon(voidIcon);
    ui->P8->setIcon(voidIcon);
    ui->P9->setIcon(voidIcon);
    for(int i=0;i<9;i++){
        data_tab[i] = 0;
    }
    currentPlayer=1;
    QPixmap gracz1(":/img/img/xsmall.bmp");
    ui->playerIcon->setPixmap(gracz1);
}

int MainWindow::isWin()
{

    if(((data_tab[0]==data_tab[1]&&data_tab[1]==data_tab[2])&&data_tab[0]!=0&&data_tab[1]!=0&&data_tab[2]!=0) || ((data_tab[3]==data_tab[4]&&data_tab[4]==data_tab[5])&&data_tab[3]!=0&&data_tab[4]!=0&&data_tab[5]!=0) || ((data_tab[6]==data_tab[7]&&data_tab[7]==data_tab[8])&&data_tab[6]!=0&&data_tab[7]!=0&&data_tab[8]!=0)){
        return 1;
    }else if(((data_tab[0]==data_tab[3]&&data_tab[3]==data_tab[6])&&data_tab[0]!=0&&data_tab[3]!=0&&data_tab[6]!=0) || ((data_tab[1]==data_tab[4]&&data_tab[4]==data_tab[7])&&data_tab[1]!=0&&data_tab[4]!=0&&data_tab[7]!=0) || ((data_tab[2]==data_tab[5]&&data_tab[5]==data_tab[8])&&data_tab[2]!=0&&data_tab[5]!=0&&data_tab[8]!=0)){
        return 1;
    }else if(((data_tab[0]==data_tab[4]&&data_tab[4]==data_tab[8])&&data_tab[0]!=0&&data_tab[4]!=0&&data_tab[8]!=0) || ((data_tab[2]==data_tab[4]&&data_tab[4]==data_tab[6])&&data_tab[2]!=0&&data_tab[4]!=0&&data_tab[6]!=0)){
        return 1;
    }
    return 0;
}

