#ifndef deska_H
#define deska_H
using namespace std;
   // tady bude kod hlavickoveho souboru


// definice trid
class Karta
{
private:
    string ukol;
    int umisteni;
    string nalezeni;
    
public:
    Karta(string jake);
    void vypis();
    string vrat_predmet();
    void umistit(int pozice);
    int porovnej(string znak);
    string zapis_kartu();
    int porovnej2(string znak);
    int vratpozici();
    string obsayenos();
    
    
};

class Balicek
{
private:
    vector<Karta> balicek_karet;
    int velikost;
    
public:
    Balicek(int pocet);
    void vypis_balicek();
    int vrat_velikost();
    string vrat_kartu(int pozice);
    void zapispozici(int pozice,int kde);
    int vrat_pozici(string znak);
    string losuj_kartu(int pozice);
    int vrat_polohu(string znak);
    int vrat_pozici(int i);
    string vrat_osazenost(int i);
    
};

class Hrac
{
private:
    string vzhled;
    int pozice;
    int kde;
    string co;
    int skore;
    int umisteni;
    char nacemstojim;
public:
    Hrac(string invzhled,int inpozice, int inskore);
    string vrat_hrace();
    int vrat_pozici();
    void uprav_pozici(int upozice);
    void uprav_umisteni(int uumisteni);
    int vrat_umisteni();
    char vrat_nacemstojim();
    void zapis_nacemstojim(char tvarek);
    void vypis();
    string vrat_co();
    int vrat_skore();
    int vrat_kde();
    void zapis_co(string coo);
    void zapis_kde(int kdee);
    void zapis_skore(int skoree);
    

  
};

class Policko
{
private:
    string tvar;
    char vyznam;
    int rotaci;
    
public:
    Policko(string vzhled_policka,int rotace);     //vzhled_policka L,I,T
    void vypis1();
    void vypis2();
    void vypis3();
    int uprav_karta(char predmet);
    int uprav_hrace(char hrac);
    char vrat_policko(int pozice);
    void rozhibej_hrace(char hrac, int umisteni);
    void otoc_policko(int rotace);
    char vrat_cotvar();
    int vrat_rotace();
    
};

class Deska
{
private:
    
    int pocet;
    vector<Policko> hraci_plocha;
    
public:
    Deska(int inpocet);
    Deska(int inpocet, string tvary, string rotaci);
    //~Deska();
    int ziskej_pocet();
    void vykreslit();
    int vloz_premety(char predmet,int pozice,int max);
    void vloz_hrace(char hrac,int pozice);
    void hejbej_hrace(char hrac,int pozice, int umisteni);
    char vrat_tvarp(int pozice, int umisteni);
    void prekresli_policko(int pozice,int rotace);
    int ziskej_velikost();
    vector<Hrac> vsunot(int pocatek,int kolik,Balicek *karet,vector<Hrac> hraci);
    Policko ziskej_policko(int pozice);
    char vrat_co(int pozice);
    int vrat_rotaci(int pozici);
};

void rozdej_karty(Hrac *hrac, Balicek *co);
void uloz_hru(Deska *hra,  Balicek *karet,vector<Hrac> hraci,string jmeno,int aktualnihrac);
void vloz_kartu(Deska *hra, Balicek *co);
void skotroluj(Hrac *hrac, Balicek *co);
vector<Hrac> otoc(Deska *hra, int strana, int rada, int rotace, Balicek *karet,vector<Hrac> hraci);
void rozmistit_hrace(Deska *hra, Hrac *hrac);
inline void pohyb_prepis(Hrac *hrac,Deska *hra,  char vzhled,int pozice, int umisteni,char predtim);
inline void pohyb_chyba(Hrac *hrac,Deska *hra,  char vzhled);
void pohyb(Deska *hra, Hrac *hrac,Balicek *karty,string znak);



#endif