#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gamesetup.h"
#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include "labyrint.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameSetup *game_setup;
    Labyrint *labyrint;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
