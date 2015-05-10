/**
 * Labyrint 2015
 *
 * @file gamesetup.cpp
 * @brief GameSetup soubor se zdrojovym kodem.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#include "gamesetup.h"
#include "ui_gamesetup.h"

GameSetup::GameSetup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameSetup)
{
    ui->setupUi(this);
}

GameSetup::~GameSetup()
{
    delete ui;
}

void GameSetup::on_pushButton_clicked()
{
    int width_height = ui->spinBox->text().toInt(); // sirka labyrintu
    int players = ui->spinBox_2->text().toInt(); // pocet hracu
    int cards = ui->spinBox_3->text().toInt(); // pocet karet
    this->labyrint = new Labyrint(false, width_height, players, cards);
    this->labyrint->paint(); // vykresleni plochy

    this->hide(); // schovani okna pro nastaveni hry
}
