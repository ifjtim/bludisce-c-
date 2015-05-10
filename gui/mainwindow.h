/**
 * Labyrint 2015
 *
 * @file mainwindow.h
 * @brief MainWindow hlavickovy soubor.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

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

/**
 * @brief Trida Labyrint
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameSetup *game_setup; // odkaz na tridu GameSetup
    Labyrint *labyrint; // odkaz na hru

private slots:
    void on_pushButton_clicked(); // obsluha tlacitka pro vytvoreni hry

    void on_pushButton_2_clicked(); // obsluha tlacitka pro nahrani hry

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
