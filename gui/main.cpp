/**
 * Labyrint 2015
 *
 * @file main.cpp
 * @brief Main soubor se zdrojovym kodem.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
