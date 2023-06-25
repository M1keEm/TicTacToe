#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int currentPlayer;
    int data_tab[9];

private slots:
    void newGame();
    int isWin();
    void P1_clicked();
    void P2_clicked();
    void P3_clicked();
    void P4_clicked();
    void P5_clicked();
    void P6_clicked();
    void P7_clicked();
    void P8_clicked();
    void P9_clicked();
public slots:
    void clicked();
};
#endif // MAINWINDOW_H
