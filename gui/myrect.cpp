#include "myrect.h"
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        pohyb(this->labyrint->deska, &this->labyrint->hraci[this->hrac],this->labyrint->balicek,"a");
        this->labyrint->paint();
    }
    if (event->key() == Qt::Key_D){
        pohyb(this->labyrint->deska, &this->labyrint->hraci[this->hrac],this->labyrint->balicek,"d");
        this->labyrint->paint();
    }
    if (event->key() == Qt::Key_W){
        pohyb(this->labyrint->deska, &this->labyrint->hraci[this->hrac],this->labyrint->balicek,"w");
        this->labyrint->paint();
    }
    if (event->key() == Qt::Key_S){
        pohyb(this->labyrint->deska, &this->labyrint->hraci[this->hrac],this->labyrint->balicek,"s");
        this->labyrint->paint();
    }
    if (event->key() == Qt::Key_Right){
        int rotace = this->labyrint->deska->vrat_rotaci(this->labyrint->width_height*this->labyrint->width_height);
        this->labyrint->rotace = rotace;

        if (this->labyrint->rotace == 3)
            this->labyrint->rotace = 0;
        else
            this->labyrint->rotace++;

        this->labyrint->deska->prekresli_policko(this->labyrint->width_height*this->labyrint->width_height, this->labyrint->rotace);
        this->labyrint->paint_single(this->labyrint->height);

    }
    if (event->key() == Qt::Key_Left){

        int rotace = this->labyrint->deska->vrat_rotaci(this->labyrint->width_height*this->labyrint->width_height);
        this->labyrint->rotace = rotace;

        if (this->labyrint->rotace == 0)
            this->labyrint->rotace = 3;
        else
            this->labyrint->rotace--;

        this->labyrint->deska->prekresli_policko(this->labyrint->width_height*this->labyrint->width_height, this->labyrint->rotace);
        this->labyrint->paint_single(this->labyrint->height);

    }
    if (event->key() == Qt::Key_E){
        if (this->hrac == this->labyrint->players-1)
            this->hrac = 0;
        else
            this->hrac++;
        this->labyrint->paint();
    }

    this->labyrint->aktual_hrac = this->hrac;
    skotroluj(&this->labyrint->hraci[this->hrac], this->labyrint->balicek);

    for (int i=0; i<this->labyrint->players; i++){
        if (this->labyrint->hraci[i].vrat_skore() == this->vyhra){
            QMessageBox msgBox;
            QString hrac = QString::number(this->hrac+1);
            msgBox.setText("Vyhral hrac c.: "+hrac);
            QPushButton *quitButton = msgBox.addButton("Konec", QMessageBox::ActionRole);
            //QPushButton *newGameButton = msgBox.addButton("Nova hra",QMessageBox::ActionRole);

            msgBox.exec();

            if (msgBox.clickedButton() == quitButton) {
                QApplication::quit();
            } /*else if (msgBox.clickedButton() == newGameButton) {
                this->game_setup = new GameSetup;
                this->game_setup->show();
                delete this->labyrint;
                this->hide();
            }*/
        }
    }


    this->labyrint->render_info();
    this->labyrint->paint();
    this->labyrint->paint_single(this->labyrint->height);

}

MyRect::MyRect(Labyrint *labyrint)
{
    this->labyrint = labyrint;
    this->hrac = 0;
    this->vyhra = this->labyrint->cards / this->labyrint->players;
    //this->labyrint->rotace = 0;
}

MyRect::~MyRect()
{

}

