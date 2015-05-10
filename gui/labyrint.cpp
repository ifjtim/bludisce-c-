#include "labyrint.h"
#include "ui_labyrint.h"
#include <QDebug>
#include "myrect.h"
Labyrint::Labyrint(bool load, int width_height, int players, int cards, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Labyrint)
{
    ui->setupUi(this);
    this->width_height = width_height;
    this->players = players;
    this->cards = cards;
    this->vec_score_players.resize(4);
    this->aktual_hrac = 0;

    this->vec_items.resize(this->width_height*this->width_height*9+9);

    int height = (this->width_height+2)*3*20;
    this->height = height;
    int width = (this->width_height+2)*3*20;
    scene = new QGraphicsScene(this);
    MyRect *rect = new MyRect(this);
    rect->setRect(0,0,width, height+300);
    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);

    load_pix();

    if (!load){
    deska = new Deska(this->width_height);
    balicek = new Balicek(this->cards);
    vloz_kartu(deska, balicek);

        for(int i=1;i<=this->players;i++){

            if(i==1)
            {
            hraci.push_back(Hrac ("1",0,0));
            rozmistit_hrace(deska, &hraci[0]);
            rozdej_karty( &hraci[0], balicek);
            }

            if(i==2)
            {
            hraci.push_back(Hrac ("2",this->width_height-1,0));
            rozmistit_hrace(deska, &hraci[1]);
            rozdej_karty( &hraci[1], balicek);
            }

            if(i==3)
            {
            hraci.push_back(Hrac ("3",this->width_height*this->width_height-this->width_height,0));
            rozmistit_hrace(deska, &hraci[2]);
            rozdej_karty( &hraci[2], balicek);
            }

            if(i==4)
            {
            hraci.push_back(Hrac ("4",this->width_height*this->width_height-1,0));
            rozmistit_hrace(deska, &hraci[3]);
            rozdej_karty( &hraci[3], balicek);
            }

        }
        paint_single(this->height);

        render_info();

    }


    view = new QGraphicsView(scene);
    view->show();

}

Labyrint::~Labyrint()
{
    delete ui;
}

void Labyrint::paint()
{
    QString test;


    while (!vec_items.empty()){
        vec_items.pop_back();
    }

    char typ_policko;
    int counter = 0, counter2 = 0;
    int i = 0, j = 0, x = 0, y = 0;
    int plus1 = 0, plus2 = 0;
    for (x = 0; x <this->width_height; x++){

        for (y = 0; y <this->width_height; y++){

            counter2 = 0;

            for (i = 0; i<3; i++){
                for (j = 0; j<3; j++){
                    typ_policko = deska->ziskej_policko(counter).vrat_policko(counter2);
                    test += typ_policko;
                    if (typ_policko == 'w'){
                        Item = scene->addPixmap(wall);
                    }
                    else if (typ_policko == '1'){
                        Item = scene->addPixmap(hrac1);
                    }
                    else if (typ_policko == '2'){
                        Item = scene->addPixmap(hrac2);
                    }
                    else if (typ_policko == '3'){
                        Item = scene->addPixmap(hrac3);
                    }
                    else if (typ_policko == '4'){
                        Item = scene->addPixmap(hrac4);
                    }
                    else if (typ_policko == 'h'){
                        Item = scene->addPixmap(hall);
                    }
                    else {
                        choose_pic(typ_policko);
                    }

                    Item->setOffset(50+20*j+plus1,50+20*i+plus2);
                    vec_items.append(Item);

                    counter2++;
                }

            }
            plus1 += 65;
            counter++;
        }
        plus1 = 0;
        plus2 += 65;
    }

}

void Labyrint::paint_single(int height)
{
    char typ_policko;
    int counter = 0;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            typ_policko = deska->ziskej_policko(deska->ziskej_velikost()-1).vrat_policko(counter);
            if (typ_policko == 'w'){
                Item = scene->addPixmap(wall);
            }
            else if (typ_policko == 'h'){
                Item = scene->addPixmap(hall);
            }
            else {
                choose_pic(typ_policko);
            }
            Item->setOffset(50+20*j,height+20*i);
            vec_items.append(Item);
            counter++;
        }

    }
    rotate_left = new QGraphicsPixmapItem;
    rotate_right = new QGraphicsPixmapItem;

    rotate_left = scene->addPixmap(arrow_left);
    rotate_left->setOffset(50,height+60);



    rotate_right = scene->addPixmap(arrow_right);
    rotate_right->setOffset(50+40,height+60);
}

void Labyrint::render_info()
{
    QSpinBox *strana;
    QSpinBox *radky;

    radky = new QSpinBox();
    radky->setMinimum(1);
    radky->setMaximum(this->width_height-2);
    radky->setSingleStep(2);
    QLabel *label_radky = new QLabel;
    label_radky->setGeometry(50,height+100,30,20);
    label_radky->setText("Radky: ");
    proxy = this->scene->addWidget(label_radky);
    radky->setGeometry(100,height+100,50,20);
    proxy = this->scene->addWidget(radky);

    QLabel *label_sloupce = new QLabel;
    label_sloupce->setGeometry(50,height+150,50,20);
    label_sloupce->setText("Strana: ");
    proxy = this->scene->addWidget(label_sloupce);

    strana = new QSpinBox();
    strana->setMinimum(1);
    strana->setMaximum(this->width_height-1);
    strana->setSingleStep(1);
    strana->setGeometry(50+50,height+150,50,20);
    proxy = this->scene->addWidget(strana);

    rotace_button = new QPushButton;
    rotace_button->setText("Odeslat rotaci");
    rotace_button->setGeometry(50,height+200,110,20);
    proxy = this->scene->addWidget(rotace_button);

    this->lab_radky = radky;
    this->lab_strana = strana;


    save_button = new QPushButton;
    save_button->setText("Ulozit hru");
    save_button->setGeometry(50,height+230,80,20);
    proxy = this->scene->addWidget(save_button);

    quit_button = new QPushButton;
    quit_button->setText("Ukoncit hru");
    quit_button->setGeometry(50,height+260,80,20);
    proxy = this->scene->addWidget(quit_button);

    QGraphicsProxyWidget *proxy;
    QLabel *label_hrac1 = new QLabel;
    QLabel *hrac1_score = new QLabel;
    QLineEdit *hrac1_score_val = new QLineEdit;
    QLabel *hrac1_predmet = new QLabel;

    QLabel *label_hrac2 = new QLabel;
    QLabel *hrac2_score = new QLabel;
    QLabel *hrac2_predmet = new QLabel;
    QLineEdit *hrac2_score_val = new QLineEdit;

    QLabel *label_hrac3 = new QLabel;
    QLabel *hrac3_score = new QLabel;
    QLabel *hrac3_predmet = new QLabel;
    QLineEdit *hrac3_score_val = new QLineEdit;

    QLabel *label_hrac4 = new QLabel;
    QLabel *hrac4_score = new QLabel;
    QLabel *hrac4_predmet = new QLabel;
    QLineEdit *hrac4_score_val = new QLineEdit;

    QString score;
    int skore;
    char typ;
    string test;

        label_hrac1->setGeometry(180,height,70,20);
        label_hrac1->setText("Hrac 1: ");
        proxy = this->scene->addWidget(label_hrac1);

        hrac1_score->setGeometry(180,height+30,70,20);
        hrac1_score->setText("Skore: ");
        proxy = this->scene->addWidget(hrac1_score);

        hrac1_score_val->setGeometry(220,height+30,20,20);
        hrac1_score_val->setDisabled(true);
        hrac1_score_val->setCursor(Qt::ArrowCursor);
        skore = this->hraci[0].vrat_skore();
        score = QString::number(skore);
        hrac1_score_val->setText(score);
        proxy = this->scene->addWidget(hrac1_score_val);

        hrac1_predmet->setGeometry(180,height+60,70,20);
        hrac1_predmet->setText("Predmet: ");
        proxy = this->scene->addWidget(hrac1_predmet);

        test = (this->hraci[0].vrat_co());
        typ = test[0];
        choose_pic(typ);
        Item->setOffset(230,height+60);
        vec_items.append(Item);
/***************************************************************/
        label_hrac2->setGeometry(300,height,70,20);
        label_hrac2->setText("Hrac 2: ");
        proxy = this->scene->addWidget(label_hrac2);

        hrac2_score->setGeometry(300,height+30,50,20);
        hrac2_score->setText("Skore: ");
        proxy = this->scene->addWidget(hrac2_score);

        hrac2_score_val->setGeometry(340,height+30,20,20);
        hrac2_score_val->setDisabled(true);
        hrac2_score_val->setCursor(Qt::ArrowCursor);
        skore = this->hraci[1].vrat_skore();
        score = QString::number(skore);
        hrac2_score_val->setText(score);
        proxy = this->scene->addWidget(hrac2_score_val);


        hrac2_predmet->setGeometry(300,height+60,70,20);
        hrac2_predmet->setText("Predmet: ");
        proxy = this->scene->addWidget(hrac2_predmet);

        test = (this->hraci[1].vrat_co());
        typ = test[0];
        choose_pic(typ);
        Item->setOffset(350,height+60);
        vec_items.append(Item);


    if (this->players == 3){

        label_hrac3->setGeometry(180,height+100,70,20);
        label_hrac3->setText("Hrac 3: ");
        proxy = this->scene->addWidget(label_hrac3);

        hrac3_score->setGeometry(180,height+130,70,20);
        hrac3_score->setText("Skore: ");
        proxy = this->scene->addWidget(hrac3_score);

        hrac3_score_val->setGeometry(220,height+130,20,20);
        hrac3_score_val->setDisabled(true);
        hrac3_score_val->setCursor(Qt::ArrowCursor);
        skore = this->hraci[2].vrat_skore();
        score = QString::number(skore);
        hrac3_score_val->setText(score);
        proxy = this->scene->addWidget(hrac3_score_val);

        hrac3_predmet->setGeometry(180,height+160,70,20);
        hrac3_predmet->setText("Predmet: ");
        proxy = this->scene->addWidget(hrac3_predmet);

        test = (this->hraci[2].vrat_co());
        typ = test[0];
        choose_pic(typ);
        Item->setOffset(230,height+160);
        vec_items.append(Item);
    }
    else if (this->players == 4){

        label_hrac3->setGeometry(180,height+100,70,20);
        label_hrac3->setText("Hrac 3: ");
        proxy = this->scene->addWidget(label_hrac3);

        hrac3_score->setGeometry(180,height+130,70,20);
        hrac3_score->setText("Skore: ");
        proxy = this->scene->addWidget(hrac3_score);

        hrac3_score_val->setGeometry(220,height+130,20,20);
        hrac3_score_val->setDisabled(true);
        hrac3_score_val->setCursor(Qt::ArrowCursor);
        skore = this->hraci[2].vrat_skore();
        score = QString::number(skore);
        hrac3_score_val->setText(score);
        proxy = this->scene->addWidget(hrac3_score_val);

        hrac3_predmet->setGeometry(180,height+160,70,20);
        hrac3_predmet->setText("Predmet: ");
        proxy = this->scene->addWidget(hrac3_predmet);

        test = (this->hraci[2].vrat_co());
        typ = test[0];
        choose_pic(typ);
        Item->setOffset(230,height+160);
        vec_items.append(Item);
/***************************************************************/
        label_hrac4->setGeometry(300,height+100,70,20);
        label_hrac4->setText("Hrac 4: ");
        proxy = this->scene->addWidget(label_hrac4);

        hrac4_score->setGeometry(300,height+130,50,20);
        hrac4_score->setText("Skore: ");
        proxy = this->scene->addWidget(hrac4_score);

        hrac4_score_val->setGeometry(340,height+130,20,20);
        hrac4_score_val->setDisabled(true);
        hrac4_score_val->setCursor(Qt::ArrowCursor);
        skore = this->hraci[3].vrat_skore();
        score = QString::number(skore);
        hrac4_score_val->setText(score);
        proxy = this->scene->addWidget(hrac4_score_val);


        hrac4_predmet->setGeometry(300,height+160,70,20);
        hrac4_predmet->setText("Predmet: ");
        proxy = this->scene->addWidget(hrac4_predmet);

        test = (this->hraci[3].vrat_co());
        typ = test[0];
        choose_pic(typ);
        Item->setOffset(350,height+160);
        vec_items.append(Item);

    }

    connect(this->save_button, SIGNAL(clicked()),this, SLOT (on_save_button_clicked()));
    connect(this->rotace_button, SIGNAL(clicked()),this, SLOT (on_rotace_button_clicked()));
    connect(this->quit_button, SIGNAL(clicked()),this, SLOT (on_quit_button_clicked()));
}

void Labyrint::choose_pic(char typ_policko)
{
    if (typ_policko == '~'){
        Item = scene->addPixmap(cloud);
    }
    else if (typ_policko == '!'){
        Item = scene->addPixmap(cog);
    }
    else if (typ_policko == '@'){
        Item = scene->addPixmap(compass);
    }
    else if (typ_policko == '#'){
        Item = scene->addPixmap(dribbble);
    }
    else if (typ_policko == '$'){
        Item = scene->addPixmap(drop);
    }
    else if (typ_policko == '%'){
        Item = scene->addPixmap(globe);
    }
    else if (typ_policko == '^'){
        Item = scene->addPixmap(hashtag);
    }
    else if (typ_policko == '&'){
        Item = scene->addPixmap(heart);
    }
    else if (typ_policko == '*'){
        Item = scene->addPixmap(location);
    }
    else if (typ_policko == '('){
        Item = scene->addPixmap(lock);
    }
    else if (typ_policko == ')'){
        Item = scene->addPixmap(mail);
    }
    else if (typ_policko == '_'){
        Item = scene->addPixmap(map);
    }
    else if (typ_policko == '+'){
        Item = scene->addPixmap(more_2);
    }
    else if (typ_policko == '{'){
        Item = scene->addPixmap(moustache);
    }
    else if (typ_policko == '}'){
        Item = scene->addPixmap(music);
    }
    else if (typ_policko == ':'){
        Item = scene->addPixmap(pause);
    }
    else if (typ_policko == '<'){
        Item = scene->addPixmap(pen_1);
    }
    else if (typ_policko == '>'){
        Item = scene->addPixmap(pie_chart);
    }
    else if (typ_policko == '?'){
        Item = scene->addPixmap(pill);
    }
    else if (typ_policko == '|'){
        Item = scene->addPixmap(plug);
    }
    else if (typ_policko == '"'){
        Item = scene->addPixmap(power);
    }
    else if (typ_policko == 'q'){
        Item = scene->addPixmap(graph_rise);
    }
    else if (typ_policko == 's'){
        Item = scene->addPixmap(eject);
    }
    else if (typ_policko == 'e'){
        Item = scene->addPixmap(fast_forward);
    }
    else {
        Item = scene->addPixmap(hall);
    }
}

void Labyrint::load_pix()
{
    int blockSize = 20;
    wall.load(":/images/wall.png");
    hall.load(":/images/hall.png");
    hrac1.load(":/images/hrac1.png");
    hrac2.load(":/images/hrac2.png");
    hrac3.load(":/images/hrac3.png");
    hrac4.load(":/images/hrac4.png");


    cloud.load(":/images/cloud.png");
    cog.load(":/images/cog.png");
    compass.load(":/images/compass.png");
    dribbble.load(":/images/dribbble.png");
    drop.load(":/images/drop.png");
    globe.load(":/images/globe.png");
    hashtag.load(":/images/hashtag.png");
    heart.load(":/images/heart.png");
    location.load(":/images/location.png");

    lock.load(":/images/lock.png");
    mail.load(":/images/mail.png");
    map.load(":/images/map.png");
    more_2.load(":/images/more_2.png");
    moustache.load(":/images/moustache.png");
    music.load(":/images/music.png");
    pause.load(":/images/pause.png");
    pen_1.load(":/images/pen_1.png");
    pie_chart.load(":/images/pie_chart.png");

    pill.load(":/images/pill.png");
    plug.load(":/images/plug.png");
    power.load(":/images/power.png");
    graph_rise.load(":/images/graph_rise.png");
    eject.load(":/images/eject.png");
    fast_forward.load(":/images/fast_forward.png");

    arrow_down.load(":/images/arrow_down.png");
    arrow_up.load(":/images/arrow_up.png");
    arrow_left.load(":/images/arrow_left.png");
    arrow_right.load(":/images/arrow_right.png");

    cloud = cloud.scaled(blockSize,blockSize);
    cog = cog.scaled(blockSize,blockSize);
    compass = compass.scaled(blockSize,blockSize);
    dribbble = dribbble.scaled(blockSize,blockSize);
    drop = drop.scaled(blockSize,blockSize);
    globe = globe.scaled(blockSize,blockSize);
    hashtag = hashtag.scaled(blockSize,blockSize);
    heart = heart.scaled(blockSize,blockSize);
    location = location.scaled(blockSize,blockSize);

    lock = lock.scaled(blockSize,blockSize);
    mail = mail.scaled(blockSize,blockSize);
    map = map.scaled(blockSize,blockSize);
    more_2 = more_2.scaled(blockSize,blockSize);
    moustache = moustache.scaled(blockSize,blockSize);
    music = music.scaled(blockSize,blockSize);
    pause = pause.scaled(blockSize,blockSize);
    pen_1 = pen_1.scaled(blockSize,blockSize);
    pie_chart = pie_chart.scaled(blockSize,blockSize);

    pill = pill.scaled(blockSize,blockSize);
    plug = plug.scaled(blockSize,blockSize);
    power = power.scaled(blockSize,blockSize);
    graph_rise = graph_rise.scaled(blockSize,blockSize);
    eject = eject.scaled(blockSize,blockSize);
    fast_forward = fast_forward.scaled(blockSize,blockSize);

    arrow_down = arrow_down.scaled(blockSize,blockSize);
    arrow_up = arrow_up.scaled(blockSize,blockSize);
    arrow_left = arrow_left.scaled(blockSize,blockSize);
    arrow_right = arrow_right.scaled(blockSize,blockSize);
}

void Labyrint::on_rotace_button_clicked()
{

   this->hraci = otoc(this->deska, this->lab_strana->value(), this->lab_radky->value(), this->rotace, this->balicek, this->hraci);
   this->paint();
   this->paint_single(this->height);
}

void Labyrint::on_save_button_clicked()
{

    bool ok;
        QInputDialog* inputDialog = new QInputDialog();
        inputDialog->setOptions(QInputDialog::NoButtons);

        QString text =  inputDialog->getText(NULL ,"Ulozit hru",
                                              "Nazev:", QLineEdit::Normal,"", &ok);
        //qDebug() << text;
         string tex = text.toStdString();

         if (ok && !text.isEmpty())
         {
            uloz_hru(this->deska, this->balicek, this->hraci, tex, this->aktual_hrac);

         }
         else {
             qDebug() << "je nutne zadat jmeno hry pro ulozeni souboru";
         }

}

void Labyrint::on_quit_button_clicked()
{
    QApplication::quit();
}

