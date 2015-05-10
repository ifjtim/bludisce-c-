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
    int width_height = ui->spinBox->text().toInt();
    int players = ui->spinBox_2->text().toInt();
    int cards = ui->spinBox_3->text().toInt();
    this->labyrint = new Labyrint(false, width_height, players, cards);
    this->labyrint->paint();

    this->hide();
}
