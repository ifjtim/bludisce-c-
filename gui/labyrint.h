/**
 * Labyrint 2015
 *
 * @file labyrint.h
 * @brief Labyrint hlavickovy soubor.
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#ifndef LABYRINT_H
#define LABYRINT_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <vector>
#include <QVector>
#include <QMouseEvent>
#include <QSpinBox>
#include <QLineEdit>
#include <QInputDialog>
#include <QDir>
#include "../src/deska.h"


namespace Ui {
class Labyrint;
}

/**
 * @brief Trida Labyrint
 */
class Labyrint : public QMainWindow
{
    Q_OBJECT

public:
    explicit Labyrint(bool load, int width_height, int players, int cards, QWidget *parent = 0);
    ~Labyrint();
    int width_height;
    int players;
    int cards;
    int height;
    int rotace;
    int radky;
    int strana;
    char predmet;
    string game_name;
    int aktual_hrac;

    QVector<QGraphicsPixmapItem *> vec_items;

    Deska *deska;
    Balicek *balicek;
    vector<Hrac> hraci;

    QGraphicsProxyWidget *proxy;
    QPushButton *rotace_button;
    QPushButton *save_button;
    QPushButton *quit_button;


    /**
     * @fn void paint()
     * @brief Vykresleni mapy labyrintu.
     */
    void paint();

    /**
     * @fn void paint_single(int height)
     * @brief Vykresleni kamene navic do prostoru pod mapou.
     * @param height Vyska plochy do ktere se vykresluje mapa
     */
    void paint_single(int height);

    /**
     * @fn void render_info()
     * @brief Vykresleni ovladacich tlacitek a informaci o hracich.
     */
    void render_info();

    /**
     * @fn void choose_pic()
     * @brief Pomocna funkce pro nacteni obrazku k predanemu znaku.
     * @param typ_policko znakova reprezentace obrazkoveho policka
     */
    void choose_pic(char typ_policko);

    /**
     * @fn void load_pix()
     * @brief Nacteni obrazku.
     */
    void load_pix();

private slots:
    void on_rotace_button_clicked(); // obsluha tlacitka pro rotaci
    void on_save_button_clicked(); // obsluha tlacitka pro ulozeni
    void on_quit_button_clicked(); // obsluha tlacitka pro ukonceni

private:



    Ui::Labyrint *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;



    QPixmap wall;
    QPixmap hall;
    QPixmap hrac1;
    QPixmap hrac2;
    QPixmap hrac3;
    QPixmap hrac4;

    QPixmap cloud;
    QPixmap cog;
    QPixmap compass;
    QPixmap dribbble;
    QPixmap drop;
    QPixmap globe;
    QPixmap hashtag;
    QPixmap heart;
    QPixmap location;

    QPixmap lock;
    QPixmap mail;
    QPixmap map;
    QPixmap more_2;
    QPixmap moustache;
    QPixmap music;
    QPixmap pause;
    QPixmap pen_1;
    QPixmap pie_chart;
    QPixmap pill;
    QPixmap plug;
    QPixmap power;
    QPixmap graph_rise;
    QPixmap eject;
    QPixmap fast_forward;

    QPixmap arrow_down;
    QPixmap arrow_up;
    QPixmap arrow_left;
    QPixmap arrow_right;


    QGraphicsPixmapItem  *Item; // pomocny odkaz na obrazek pro ulozeni
    QGraphicsPixmapItem  *rotate_left;
    QGraphicsPixmapItem  *rotate_right;
    QSpinBox *lab_radky; // pomocny odkaz pro pristup k datum
    QSpinBox *lab_strana; // pomocny odkaz pro pristup k datum
};

#endif // LABYRINT_H
