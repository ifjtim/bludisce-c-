/**
 * Labyrint 2015
 *
 * @file myrect.cpp
 * @brief MyRect soubor se zdrojovym kodem.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */
#include "myrect.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){ // pokud se stiskne klavesa A
        pohyb(this->labyrint->deska, &this->labyrint->hraci[this->hrac],this->labyrint->balicek,"a"); // upravi se mapa pomoci funkce pobyb
        this->labyrint->paint(); // prekresleni mapy labyrintu
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
        int rotace = this->labyrint->deska->vrat_rotaci(this->labyrint->width_height*this->labyrint->width_height);// aktualni rotace posledniho kamene
        this->labyrint->rotace = rotace;

        if (this->labyrint->rotace == 3) // pokud jsme otocili 4x vratime se do puvodni pozice
            this->labyrint->rotace = 0;
        else
            this->labyrint->rotace++;// otaceni kamenem

        this->labyrint->deska->prekresli_policko(this->labyrint->width_height*this->labyrint->width_height, this->labyrint->rotace); // nastaveni nove rotace kamene
        this->labyrint->paint_single(this->labyrint->height);// vykresleni posledniho volneho kamene

    }
    if (event->key() == Qt::Key_Left){

        int rotace = this->labyrint->deska->vrat_rotaci(this->labyrint->width_height*this->labyrint->width_height);
        this->labyrint->rotace = rotace;

        if (this->labyrint->rotace == 0)
            this->labyrint->rotace = 3;
        else
            this->labyrint->rotace--; // opacne rotace kamene

        this->labyrint->deska->prekresli_policko(this->labyrint->width_height*this->labyrint->width_height, this->labyrint->rotace);
        this->labyrint->paint_single(this->labyrint->height);

    }
    if (event->key() == Qt::Key_E){ // zmena hrace
        if (this->hrac == this->labyrint->players-1)
            this->hrac = 0;
        else
            this->hrac++;
        this->labyrint->paint(); // prekresleni
    }

    this->labyrint->aktual_hrac = this->hrac; // aktualni hrac
    skotroluj(&this->labyrint->hraci[this->hrac], this->labyrint->balicek); // prirazeni noveho predmetu + upraveni skore

    for (int i=0; i<this->labyrint->players; i++){
        if (this->labyrint->hraci[i].vrat_skore() == this->vyhra){ // porovnavani skore
            QMessageBox msgBox;
            QString hrac = QString::number(this->hrac+1);
            msgBox.setText("Vyhral hrac c.: "+hrac);
            QPushButton *quitButton = msgBox.addButton("Konec", QMessageBox::ActionRole);

            msgBox.exec();

            if (msgBox.clickedButton() == quitButton) {
                QApplication::quit(); // ukonceni hry
            }

        }
    }


    this->labyrint->render_info(); // aktualizace skore
    this->labyrint->paint(); // prekresleni sceny
    this->labyrint->paint_single(this->labyrint->height); // prekresleni rotace volneho kamene

}

MyRect::MyRect(Labyrint *labyrint)
{
    this->labyrint = labyrint;
    this->hrac = 0;
    this->vyhra = this->labyrint->cards / this->labyrint->players; // minimalni pocet kamenu postacujici k vyhre
}

MyRect::~MyRect()
{

}

