#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include <string>

#include "deska.h"
#include "labyrint.h"
#include "gamesetup.h"

class MyRect: public QGraphicsRectItem
{
public:

    MyRect(Labyrint *labyrint);
    ~MyRect();
    Labyrint *labyrint;
    GameSetup *game_setup;
    int hrac;
    int rotace_right;
    int vyhra;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYRECT_H
