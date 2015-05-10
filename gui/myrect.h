/**
 * Labyrint 2015
 *
 * @file myrect.h
 * @brief MyRect hlavickovy soubor.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <string>


#include "labyrint.h"
#include "gamesetup.h"
#include "../deska.h"

/**
 * @brief Trida Labyrint
 */
class MyRect: public QGraphicsRectItem
{
public:

    MyRect(Labyrint *labyrint);
    ~MyRect();
    Labyrint *labyrint; //odkaz na hru
    GameSetup *game_setup; // odkaz na vytvoreni hry
    int hrac; // aktualni hrac
    int vyhra; // minimalni pocet nutny pro vyhru

protected:
    /**
     * @fn void keyPressEvent()
     * @brief Obsluha klavesnice.
     */
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYRECT_H
