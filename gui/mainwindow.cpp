#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->game_setup = new GameSetup;
    this->game_setup->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->game_setup = new GameSetup;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Nacist mapu"),
                                                    "",
                                                    tr("Mapa (*.txt)"));
    //qDebug() << fileName;
    string nacata = fileName.toStdString();

    FILE *soubor;
    int pocet,pocet_karet,pocet_hracu,tah=0,vloz,rada,vyhra=0,porvykr=0,kroky=1;
    string znak,nacist,jmeno_hry,prepast;
    vector<Hrac> hraci;
    Deska *d;
    Balicek *pocek;

    int num,pocet_ka,ci=0,pozicc,pocet_h=0,pos_h=0,umis_h=0,skore_h=0;
    char neco,pocett[3],umisteni_karet[10],hrac[4];
    string covlastne,rotace,anone,vzhled_h,stol,hladani;
    vector<int> pozi;
    vector<string> vlastnost;

    char *cstr = new char[nacata.length() + 1];
    strcpy(cstr, nacata.c_str());

    soubor = fopen(cstr, "r");

    delete [] cstr;
    if(soubor==NULL) {
       qDebug() <<"chybne jmeno";
       exit(1);
    }
    fscanf(soubor, "%d", &num);
    pocet=num;
    //qDebug() << num;
    neco=fgetc(soubor);
    //qDebug() << "1"<<neco;
    neco= fgetc (soubor);

    do{
        covlastne.push_back(neco);
        neco= fgetc (soubor);

    }while (neco != '\n');

    neco= fgetc (soubor);

    do{
        rotace.push_back(neco);
        neco= fgetc (soubor);
    } while (neco != '\n');

    pocett[0]= fgetc (soubor);
    pocett[1]= fgetc (soubor);
    pocett[2]= '\0';
    pocet_ka = atoi (pocett);
    //qDebug() <<pocett<<"dd";
    //qDebug()<< pocet_ka <<"dd";
    neco= fgetc (soubor);
    neco= fgetc (soubor);

    for(int i=0;i<=pocet_ka-1;i++) {

        do{
           umisteni_karet[ci]= neco;
           // cout<<neco<<endl;
           neco= fgetc (soubor);
           ci++;

        }while (neco != '\n' && neco !=' ');
        umisteni_karet[ci]='\0';
        ci=0;
        pozicc= atoi (umisteni_karet);
        pozi.push_back(pozicc);
        //cout<<umisteni_karet<<"umi"<<endl;
     }
    neco= fgetc (soubor);
    neco= fgetc (soubor);

    for(int i=0;i<=pocet_ka-1;i++)
    {

        do{
            // cout<<neco<<endl;
            anone.push_back(neco);
            neco= fgetc (soubor);
        }while (neco != '\n' && neco !=' ');

        vlastnost.push_back(anone);
        neco= fgetc (soubor);
        //cout<<"umi"<<anone<<"umi"<<endl;
        anone="";
     }

    neco= fgetc (soubor);
    //cout<<neco<<"cislo_hracu"<<endl;
    pocet_h=int(neco);
    pocet_h=pocet_h-48;
    neco= fgetc (soubor);
    //cout<<neco<<" xhv"<<endl;
    pocet_hracu=pocet_h;
    pocet_karet=pocet_ka;
    //qDebug() << pocet_hracu << " " << pocet_karet;

    this->labyrint = new Labyrint(true, num, pocet_hracu, pocet_karet);

    this->labyrint->deska = new Deska(num,covlastne,rotace);

    this->labyrint->balicek = new Balicek(pocet_ka,pozi, vlastnost);

    vloz_kartu2(this->labyrint->deska, this->labyrint->balicek);



    for(int i=0;i<=pocet_h-1;i++)
    {
        for(int j=0;j<=5;j++)
        {
            ci=0;
            do{

                neco= fgetc (soubor);
                hrac[ci]=neco;
                ci++;
             }while (neco != '\n' && neco !=' ');
             hrac[ci-1]='\0';
             if(j==0)vzhled_h=hrac;
             if(j==1)pos_h = atoi(hrac);
             if(j==2)umis_h=atoi(hrac);
             if(j==3)skore_h=atoi(hrac);
             if(j==4)stol=hrac;
             if(j==5)hladani=hrac;
             //cout<<hrac<<"xhrav"<<endl;
        }
        neco= fgetc (soubor);
        //cout<<vzhled_h<<" "<<pos_h<<"  "<<umis_h<<" "<<skore_h<<" "<<stol<<"hh"<<endl;
        this->labyrint->hraci.push_back(Hrac (vzhled_h,pos_h,skore_h,umis_h,stol[0],hladani));
        this->labyrint->deska->hejbej_hrace(vzhled_h[0],pos_h,umis_h);
        //rozdej_karty( &hraci[i], pocek);
   }
    neco= fgetc (soubor);
    //neco= fgetc (soubor);
    tah=int(neco);
    tah=tah-48;

    //cout<<j<<"cislo_hracu"<<endl;
    fclose(soubor);
    this->labyrint->paint();
    this->labyrint->paint_single(this->labyrint->height);
    this->labyrint->render_info();

    this->hide();
}
