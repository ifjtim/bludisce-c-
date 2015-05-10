/**
 * Labyrint 2015
 *
 * @file gamesetup.h
 * @brief GameSetup hlavickovy soubor.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "labyrint.h"

#include <QMainWindow>

namespace Ui {
class GameSetup;
}

/**
 * @brief Trida GameSetup
 */
class GameSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = 0);
    ~GameSetup();
    Labyrint *labyrint; // odkaz na hru pro pristup k datum

private slots:
    void on_pushButton_clicked(); // obsluha tlacitka pro vytvoreni hry

private:
    Ui::GameSetup *ui;
};

#endif // GAMESETUP_H
