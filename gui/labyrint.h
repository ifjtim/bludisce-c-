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
#include "deska.h"
namespace Ui {
class Labyrint;
}

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
    void paint();
    void paint_single(int height);
    void render_info();
    void choose_pic(char typ_policko);
    void load_pix();
    QVector<QGraphicsPixmapItem *> vec_items;
    Deska *deska;
    Balicek *balicek;
    vector<Hrac> hraci;
    char predmet;
    QVector<int> vec_score_players;
    QVector<QGraphicsPixmapItem *> vec_items_players;
    string game_name;
    int aktual_hrac;
    QGraphicsProxyWidget *proxy;
    QPushButton *rotace_button;
    QPushButton *save_button;
    QPushButton *quit_button;

private slots:
    void on_rotace_button_clicked();
    void on_save_button_clicked();
    void on_quit_button_clicked();

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


    QGraphicsPixmapItem  *Item;
    QGraphicsPixmapItem  *rotate_left;
    QGraphicsPixmapItem  *rotate_right;
    QSpinBox *lab_radky;
    QSpinBox *lab_strana;
};

#endif // LABYRINT_H
