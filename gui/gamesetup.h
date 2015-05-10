#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "labyrint.h"

#include <QMainWindow>

namespace Ui {
class GameSetup;
}

class GameSetup : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSetup(QWidget *parent = 0);
    ~GameSetup();
    Labyrint *labyrint;

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameSetup *ui;
};

#endif // GAMESETUP_H
