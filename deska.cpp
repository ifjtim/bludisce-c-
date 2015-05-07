#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    int rotace;
    
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
    
};

class Deska
{
private:
    
    int pocet;
    vector<Policko> hraci_plocha;
    
public:
    Deska(int inpocet);
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
};

void rozdej_karty(Hrac *hrac, Balicek *co);

//*****************fukce balicek *********************************************************************

    Balicek::Balicek(int pocet)
    {
        string ukol= "~!@#$%^&*()_+{}:<>?|\"qser";
        string vul;
        for(int i=0;i<=pocet-1;i++){
           vul=ukol[i]; 
           //cout<< vul <<endl;
        balicek_karet.push_back(Karta (vul));
            
        }
        velikost=pocet;
        
    }
    
    void Balicek::vypis_balicek()
    {
        for(int i =0 ;i<=balicek_karet.size()-1;i++){
        
            balicek_karet[i].vypis(); 
        }
        
    }
    
    string Balicek::vrat_kartu(int pozice)
    {
        return balicek_karet[pozice].vrat_predmet();
    }
    void Balicek::zapispozici(int pozice,int kde)
    {
        balicek_karet[pozice].umistit(kde);
    }
    int Balicek::vrat_velikost(){
    
        return velikost;
    }
    
   int Balicek::vrat_pozici(string znak){
       int kontrola=0;
        for(int i =0 ;i<=balicek_karet.size()-1;i++){
        
            kontrola=balicek_karet[i].porovnej(znak); 
            if(kontrola==1)return i;
        }
        return -1;
   }
   
    string Balicek::losuj_kartu(int pozice)
    {
        string neco="ne";
        int pocitak=0;
        while(neco=="ne"){
            neco=balicek_karet[pozice].zapis_kartu();
            pozice++;
                if(pozice==velikost)
                {
                    pocitak++;
                    if(pocitak==4)break;
                    pozice=0;
                }
        }
        return neco;
    }
    
    int Balicek::vrat_polohu(string znak){
       int kontrola=-1;
        for(int i =0 ;i<=balicek_karet.size()-1;i++){
        
            kontrola=balicek_karet[i].porovnej2(znak); 
            if(kontrola!=-1)return kontrola;
        }
        return -1;
   }
    
//********funkce karta**********************************************************************************    
    Karta::Karta(string jake)
    {
        ukol=jake;
        nalezeni="ne";
    }
    int Karta::porovnej(string znak){
        if(znak==ukol) return 1;
        else return -1;
    }
    
    int Karta::porovnej2(string znak){
        if(znak==ukol) return umisteni;
        else return -1;
    }
    
    void Karta::vypis()
    {
        cout<< ukol<<" " ;
        cout<< umisteni<<endl;
    }
    void Karta::umistit(int pozice){
     
        umisteni=pozice;
    }
    
    string Karta::vrat_predmet()
    {
        return ukol;
    }
    
    string Karta::zapis_kartu(){
        if(nalezeni=="ne"){
        
            nalezeni="ano";
            return ukol;
        }
        else return "ne";
        
    }
    
    
//***************fukce deska***********************************************************************
 
 
 Deska::Deska(int inpocet)
 {
      
     srand (time(NULL));
     int nahodne_natoceni,nahodne_vyber;
     int d=1,rad=1,sloupec=1;
     string neco;
     
    pocet=inpocet; 
    int pocet_T=0,pocet_L=0,pocet_I=0,vypocet=0;
    vypocet=inpocet*inpocet/3;
    //cout << vypocet<< endl;
    if(inpocet==9){
    pocet_T=vypocet+1-21;
    pocet_L=vypocet-4;
    pocet_I=vypocet;
        
    }
    else if(inpocet==5)
    {
        pocet_T=vypocet+1-4;
        pocet_L=vypocet+1-4;
        pocet_I=vypocet;
    }
    else if(inpocet==7)
    {
        pocet_T=vypocet+1-12;
        pocet_L=vypocet+1-4;
        pocet_I=vypocet;
    }
    else if(inpocet==11)
    {
        pocet_T=vypocet+1-32;
        pocet_L=vypocet+1-4;
        pocet_I=vypocet;
    }
    vypocet=pocet_T+pocet_L+pocet_I;
    //cout << vypocet<< endl;
    //generovani desky
    for(int i=1; i<=(inpocet*inpocet)+1;i++){
       
      // cout<<nahodne_natoceni<<endl;
       if(sloupec==inpocet+1)
       {
           sloupec=1;
           rad++;
           
       }
       //cout<<sloupec<<endl;
       
    if (i==1)
    {
        
        hraci_plocha.push_back(Policko ("L",1));
    }
    else if (i==inpocet)
    {
        hraci_plocha.push_back(Policko ("L",2));
    }
    else if (i==((inpocet*inpocet)-inpocet)+1)
    {
        hraci_plocha.push_back(Policko ("L",0));
    }
    else if (i==(inpocet*inpocet))
    {
        hraci_plocha.push_back(Policko ("L",3));
    }
    else if (sloupec%2!=0 && rad%2!=0)
    {
        if(rad==1)
        {
            hraci_plocha.push_back(Policko ("T",0));
        }
        else if(rad==inpocet)
        {
            hraci_plocha.push_back(Policko ("T",2));
        }
        else if(sloupec==1)
        {
            hraci_plocha.push_back(Policko ("T",3));
        }
        else if(sloupec==inpocet)
        {
            hraci_plocha.push_back(Policko ("T",1));
        }
        else hraci_plocha.push_back(Policko ("T",nahodne_natoceni));
       
    }
    else
    {
        
        nahodne_natoceni  = rand() % 4 + 0;
        nahodne_vyber  = rand() % 3 + 1;
        //cout<< nahodne_vyber<< endl;
        if(nahodne_vyber==1)
        {
            if(pocet_T!=0)
            {
                neco="T";
                pocet_T--;
            }
            else if(pocet_L>pocet_I)
            {
                neco="L";
                pocet_L--;
            }
            else
            {
                neco="I";
                pocet_I--;
            }
        }
        else if(nahodne_vyber==2)
        {
         if(pocet_L!=0)
            {
                neco="L";
                pocet_L--;
            }
            else if(pocet_T>pocet_I)
            {
                neco="T";
                pocet_T--;
            }
            else
            {
                neco="I";
                pocet_I--;
            }   
        }
        else if(nahodne_vyber==3)   
        {
            if(pocet_I!=0)
            {
                neco="I";
                pocet_I--;
            }
            else if(pocet_L>pocet_T)
            {
                neco="L";
                pocet_L--;
            }
            else
            {
                neco="T";
                pocet_T--;
            }
        }
        else neco="w";
    hraci_plocha.push_back(Policko (neco,nahodne_natoceni));
    }
    sloupec++;
    }
 }
 
 int Deska::ziskej_pocet(){
 
     return pocet;
}
int Deska::ziskej_velikost(){
 
     return hraci_plocha.size();
}
 
/* Deska::~Deska()
 {
     while (!hraci_plocha.empty()) // Opakuj, dokud není prázdný (Dokud nemá 0 prvků )
    {
        hraci_plocha.back().~Policko();
        hraci_plocha.pop_back(); // Odeberu poslední prvek
    }
 }
 */
 
 
 void Deska::vykreslit(){
 //cout << hraci_plocha.size()<< endl;
 for(int i =0 ;i<=hraci_plocha.size()-2;i+=pocet){
  for(int j =0 ;j<=pocet-1;j++){
     hraci_plocha[i+j].vypis1();
  }
  cout << endl;
  for(int j =0 ;j<=pocet-1;j++){
     hraci_plocha[i+j].vypis2();
  }
  cout << endl;
  for(int j =0 ;j<=pocet-1;j++){
     hraci_plocha[i+j].vypis3();
  }
  cout << endl;
  cout << endl;
}
  
  hraci_plocha.back().vypis1();
  cout << endl;
  hraci_plocha.back().vypis2();
  cout << endl;
  hraci_plocha.back().vypis3();   
}

int Deska::vloz_premety(char predmet,int pozice,int max){
    //cout<<predmet<<endl;
    int kontrola=0;
    while(kontrola!=1){
       kontrola= hraci_plocha[pozice].uprav_karta(predmet);
       if(kontrola==1)break;
       pozice++;
       if(pozice==max)
           pozice=0;
    }
   return pozice; 
}

void Deska::vloz_hrace(char hrac,int pozice){
    //cout<<predmet<<endl;
   hraci_plocha[pozice].uprav_hrace(hrac);

    
}

void Deska::hejbej_hrace(char hrac,int pozice, int umisteni){
    //cout<<predmet<<endl;
   hraci_plocha[pozice].rozhibej_hrace(hrac,umisteni);

    
}

char Deska::vrat_tvarp(int pozice, int umisteni)
{
   return hraci_plocha[pozice].vrat_policko(umisteni);
}
void Deska::prekresli_policko(int pozice,int rotace)
{
    hraci_plocha[pozice].otoc_policko(rotace);
}

vector<Hrac> Deska::vsunot(int pocatek,int kolik,Balicek *karet,vector<Hrac> hraci)
{
   int velikost=hraci_plocha.size(),pomocny_pocet=pocatek,pozice_karty=-1,hrac=0,kdoo=-1,kamm=-1,pozice,umisteni;
   vector<int> kdo;
   vector<int> kam;
   char kontrola,tedka,predtim;
   string pomocnzy,vzhled;
    Policko pomoc("w",0),pomoc2("w",0);
    pomoc2=hraci_plocha[pocatek];
    kontrola=hraci_plocha[pocatek].vrat_policko(4);
     pomocnzy.push_back(kontrola);
     pozice_karty=karet->vrat_pozici(pomocnzy);
     /*for(int i=0 ;i<=hraci.size()-1;i++)
     {
      hrac=hraci[i].vrat_pozici();
      if(hrac==pocatek)hraci[i].uprav_pozici(pocatek+kolik);
     }*/
   
    for(int i=1;i<=pocet-1;i++){
        for(int j=0 ;j<=hraci.size()-1;j++)
        {
            hrac=hraci[j].vrat_pozici();
            if(hrac==pomocny_pocet){
                kdo.push_back(j);
                kam.push_back(pomocny_pocet+kolik);
               // hraci[j].uprav_pozici(pomocny_pocet+kolik);
            }
            //hraci[j].vypis();
            //cout<<j<<endl;
        }
        
        
        pomocny_pocet+=kolik;
        if(pozice_karty!=-1){
            //cout<<pozice_karty<<" sadbashd shbdha "<< pomocny_pocet <<" " <<pomocnzy<<endl;
            karet->zapispozici(pozice_karty,pomocny_pocet);
        }
        pomoc=hraci_plocha[pomocny_pocet];
        //hrace
         
        //presouvani pozice
        kontrola=hraci_plocha[pomocny_pocet].vrat_policko(4);
        pomocnzy="";
        pomocnzy.push_back(kontrola);
        pozice_karty=karet->vrat_pozici(pomocnzy);
       
        hraci_plocha[pomocny_pocet]=pomoc2;
        pomoc2=pomoc;
    
    
    }
    //cout<<kam.size()<<endl;
    int neco=kam.size();
    neco=neco-1;
    //cout<<neco<<endl;
   
        
    
    
    hraci_plocha[pocatek]=hraci_plocha[velikost-1];
    
    //umisteni karty presun
    kontrola=hraci_plocha[velikost-1].vrat_policko(4);
    pomocnzy="";
    pomocnzy.push_back(kontrola);
    pozice_karty=karet->vrat_pozici(pomocnzy);
    if(pozice_karty!=-1){
       //cout<<pozice_karty<<" "<< pomocny_pocet <<" " <<pomocnzy<<endl;
        karet->zapispozici(pozice_karty,pocatek);
    }
    hraci_plocha[velikost-1]=pomoc;
    
     kontrola=pomoc.vrat_policko(4);
     pomocnzy="";
    pomocnzy.push_back(kontrola);
    pozice_karty=karet->vrat_pozici(pomocnzy);
    if(pozice_karty!=-1){
       // cout<<pozice_karty<<" "<< pomocny_pocet <<" " <<pomocnzy<<endl;
        karet->zapispozici(pozice_karty,velikost-1);
    }
    //teleportin hrace
        for(int j=0 ;j<=hraci.size()-1;j++)
        {
            hrac=hraci[j].vrat_pozici();
           // cout<<pomocny_pocet<<"pom"<<hrac<<"s"<<endl;
            if(hrac==pomocny_pocet){
                
                //pozice=hraci[j].vrat_pozici();
                umisteni=hraci[j].vrat_umisteni();
                vzhled=hraci[j].vrat_hrace();
                tedka=hraci[j].vrat_nacemstojim();
                hejbej_hrace(tedka,velikost-1, umisteni);
                predtim=vrat_tvarp(pocatek, 4);
                
                hraci[j].zapis_nacemstojim(predtim);
                    hraci[j].uprav_pozici(pocatek);
                    hraci[j].uprav_umisteni(4);
                    hejbej_hrace(vzhled[0],pocatek, 4);
            }      
               // hraci[j].uprav_pozici();
            }
             for(int z=0;z<=neco;z++){
        
        kdoo=kdo[z];
            kamm=kam[z];
            hraci[kdoo].uprav_pozici(kamm);
            //cout<<z<<endl;
        }
    return hraci;
}
//******************fukce policko**********************************************************************
  Policko::Policko(string vzhled_policka,int rotace)
 {
     vyznam=vzhled_policka[0];
   //string vzhled=str(vzhled_policka);
   if ("L"==vzhled_policka)
   {    
       
       if (0==rotace)
       {
           tvar= "whwwhhwww";
       }
       else if (1==rotace)
       {
           tvar= "wwwwhhwhw";
       }
       else if (2==rotace)
       {
           tvar= "wwwhhwwhw";
       }
       else if (3==rotace)
       {
           tvar= "whwhhwwww";
       }
       else
       {
           printf("chyba");
       }
   }
       
     if ("T"==vzhled_policka)
     {    
       if (0==rotace)
       {
           tvar= "wwwhhhwhw";
       }
       else if (1==rotace)
       {
           tvar= "whwhhwwhw";
       }
       else if (2==rotace)
       {
           tvar= "whwhhhwww";
       }
       else if (3==rotace)
       {
           tvar= "whwwhhwhw";
       }
       else
       {
           printf("chyba");
       }
 
     } 
     
       if ("I"==vzhled_policka)
     {    
       if (0==rotace)
       {
           tvar= "whwwhwwhw";
       }
       else if (1==rotace)
       {
           tvar= "wwwhhhwww";
       }
       else if (2==rotace)
       {
           tvar= "whwwhwwhw";
       }
       else if (3==rotace)
       {
           tvar= "wwwhhhwww";
       }
       else
       {
           printf("chyba");
       }
 
     }
     if ("w"==vzhled_policka)
     {
         tvar= "wwwwwwwww";
     }
    }
    
 void Policko::vypis1(){
 
     cout << tvar[0]<<tvar[1]<<tvar[2]<<" ";
     
}
 void Policko::vypis2(){
 
     
     cout << tvar[3]<<tvar[4]<<tvar[5]<<" ";
    
}
 void Policko::vypis3(){
 
     
     cout << tvar[6]<<tvar[7]<<tvar[8]<<" ";
}

char Policko::vrat_policko(int pozice){
 
     
     return tvar[pozice];
}

int Policko::uprav_karta(char predmet){
   // string volovina=str(tvar[4]);
   // char neco=tvar[4];
   // cout<<predmet<<endl;
    if(tvar[4]=='h')
    {
        tvar[4]=predmet;
        //cout<<tvar[3]<<tvar[4]<<tvar[5]<<" "<<endl;
        return 1;
    }
    else return -1;
    
}

int Policko::uprav_hrace(char hrac){
    tvar[4]=hrac;
    return 1;
    
}

void Policko::rozhibej_hrace(char hrac, int umisteni){
 
    tvar[umisteni]=hrac;
    
}

void Policko::otoc_policko(int rotace){
    char stre=tvar[4];
    string stred;
    stred.push_back(stre);
    //string stred(stre);
    //cout<<"vul"<<vyznam<<endl;
  if (vyznam=='L')
   {    
       
       if (0==rotace)
       {
           tvar= "whww"+stred;
           tvar+="hwww";
       }
       else if (1==rotace)
       {
           tvar= "wwww"+stred;
           tvar+="hwhw";
       }
       else if (2==rotace)
       {
           tvar= "wwwh"+stred;
           tvar+="wwhw";
       }
       else if (3==rotace)
       {
           tvar= "whwh"+stred;
           tvar+="wwww";
       }
       else
       {
           printf("chyba");
       }
   }
       
     if (vyznam=='T')
     {    
       if (0==rotace)
       {
           tvar= "wwwh"+stred;
           tvar+="hwhw";
       }
       else if (1==rotace)
       {
           tvar= "whwh"+stred;
           tvar+="wwhw";
       }
       else if (2==rotace)
       {
           tvar= "whwh"+stred;
           tvar+="hwww";
       }
       else if (3==rotace)
       {
           tvar= "whww"+stred;
           tvar+="hwhw";
       }
       else
       {
           printf("chyba");
       }
 
     } 
     
       if (vyznam=='I')
     {    
       if (0==rotace|| 2==rotace)
       {
           tvar= "whww"+stred;
           tvar+="wwhw";
       }
       else if (1==rotace || 3==rotace)
       {
           tvar= "wwwh"+stred;
           tvar+="hwww";
       }
       
       else
       {
           printf("chyba");
       }
 
     }
     if (vyznam=='w')
     {
         tvar= "wwwwwwwww";
     }
     //cout<<"vul"<<tvar<<endl;
}
//********************hrac****************************************************
Hrac::Hrac(string invzhled,int inpozice,int inskore){
    umisteni=4;
    vzhled=invzhled;
    pozice=inpozice;
    skore=inskore;
}
string Hrac::vrat_hrace()
{
    return vzhled;
}

void Hrac::vypis()
{
    cout<<"hrac"<<pozice<<endl;
}

void Hrac::uprav_pozici(int upozice)
{
    pozice=upozice;
}

void Hrac::uprav_umisteni(int uumisteni)
{
    umisteni=uumisteni;
}

int Hrac::vrat_pozici()
{
 return pozice;   
}

int Hrac::vrat_umisteni()
{
 return umisteni;   
}

char Hrac::vrat_nacemstojim()
{
 return nacemstojim;   
}

string Hrac::vrat_co()
{
 return  co;  
}

int Hrac::vrat_skore()
{
 return  skore;   
}

int Hrac::vrat_kde()
{
 return  kde;   
}

void Hrac::zapis_co(string coo)
{
   co=coo;
    
   
}

void Hrac::zapis_skore(int skoree)
{
  skore=skore+skoree;
   
    
}

void Hrac::zapis_kde(int kdee)
{
   kde=kdee;
    
}
void Hrac::zapis_nacemstojim(char tvarek)
{
    nacemstojim=tvarek;
}
/***********funkce**********************************************************/
void vloz_kartu(Deska *hra, Balicek *co){
    int opakovani,vrat_p=0, nahodne_umisteni=0,velikost=0;
    string ukarta;
    velikost=hra->ziskej_pocet();
    velikost*=velikost;
    velikost-=1;
     srand (time(NULL));
    opakovani=co->vrat_velikost();
    for (int i=0;i<=co->vrat_velikost()-1;i++){
     nahodne_umisteni  = rand() % velikost + 0;
     //cout<<"nag"<<nahodne_umisteni << velikost<<endl;
        ukarta=co->vrat_kartu(i);
        vrat_p=hra->vloz_premety(ukarta[0],nahodne_umisteni,velikost);
         co->zapispozici( i, vrat_p);
        // cout<<"karta "<<ukarta[0]<<" "<<i<<" "<<vrat_p<<endl;
        
        
    }
}
   
void skotroluj(Hrac *hrac, Balicek *co){
    string hledany;
    int pozice_hledaneho,pozice_hrace;
    hledany=hrac->vrat_co();
    pozice_hledaneho=co->vrat_polohu(hledany);
    pozice_hrace=hrac->vrat_pozici();
    // cout<<"poch"<<pozice_hledaneho<<"hrac"<<pozice_hrace<<hledany<<endl;
    if(pozice_hledaneho==pozice_hrace){
        //cout<<"bing"<<endl;
        hrac->zapis_skore(1);
        rozdej_karty(hrac,co);
        
    }
    //cout<<ukarta<<endl;
     
}
   
void rozdej_karty(Hrac *hrac, Balicek *co){
    string ukarta;
    int  nahodne_umisteni,veli=co->vrat_velikost() ;
    srand (time(NULL));
    nahodne_umisteni  = rand() % veli + 0;
    ukarta=co->losuj_kartu(nahodne_umisteni);
    hrac->zapis_co(ukarta);
    //cout<<ukarta<<endl;
     
}



vector<Hrac> otoc(Deska *hra, int strana, int rada, int rotace, Balicek *karet,vector<Hrac> hraci){
     int velikost,pocet;
    // Policko pomocne;
   
    velikost=hra->ziskej_velikost();
    velikost-=1;
    pocet=hra->ziskej_pocet();
   // cout <<"velkz"<<velikost<<endl;
    if(strana==1)
    {
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,pocet,karet,hraci);
        
       
    }
    else if(strana==2)
    {
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,-1,karet,hraci);
    }
     else if(strana==3)
    {
        pocet=pocet-pocet-pocet;
        //cout<<"bugi"<<pocet<<endl;
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,pocet,karet,hraci);
    }
    
     else if(strana==4)
    {
        
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,1,karet,hraci);
    }
    karet->vypis_balicek();
    
    return hraci;
}

void rozmistit_hrace(Deska *hra, Hrac *hrac){
    int pozice;
    string vzhled;
    char cotam;
   
    
        vzhled=hrac->vrat_hrace();
        pozice=hrac->vrat_pozici();
        cotam=hra->vrat_tvarp(pozice, 4);
        hrac->zapis_nacemstojim(cotam);
       // cout<<cotam<<endl;
        hra->vloz_hrace(vzhled[0],pozice);
         
}

inline void pohyb_prepis(Hrac *hrac,Deska *hra,  char vzhled,int pozice, int umisteni,char predtim){
                    hrac->zapis_nacemstojim(predtim);
                    hrac->uprav_pozici(pozice);
                    hrac->uprav_umisteni(umisteni);
                    hra->hejbej_hrace(vzhled,pozice, umisteni);
                    
}

inline void pohyb_chyba(Hrac *hrac,Deska *hra,  char vzhled){
    int umisteni,pozice;
                    cout<<"spatny tah"<<endl;
                      pozice=hrac->vrat_pozici();
                      umisteni=hrac->vrat_umisteni();
                      
                    hra->hejbej_hrace(vzhled,pozice, umisteni);
                    
}

void pohyb(Deska *hra, Hrac *hrac,Balicek *karty,string znak){
    int pozice,i=0,max=hra->ziskej_pocet(),umisteni=0;
    string vzhled;
    
    char predtim,tedka;
    
     pozice=hrac->vrat_pozici();
     umisteni=hrac->vrat_umisteni();
      vzhled=hrac->vrat_hrace();
     
     
     if(znak=="w")
     {
         if(umisteni==0)
         {
              pozice=pozice-max;
              if(pozice>=0)
              {
                   vzhled=hrac->vrat_hrace();
                  tedka=hrac->vrat_nacemstojim();
                  hra->hejbej_hrace(tedka,pozice+max, umisteni);
                  umisteni=6;
                  predtim=hra->vrat_tvarp(pozice, umisteni);
                 
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                    pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }      
              }
              else cout<<"chybny udaj"<<endl;
         }
          else if(umisteni==1)
         {
             pozice=pozice-max;
              if(pozice>=0)
              {
                    vzhled=hrac->vrat_hrace();
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice+max, umisteni);
                    umisteni=7;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                        pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);  
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else if(umisteni==2)
         {
             pozice=pozice-max;
              if(pozice>=0)
              {
                    
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice+max, umisteni);
                    umisteni=8;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                        pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else
         {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice, umisteni);
                    umisteni=umisteni-3;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                        pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
         } 
     }
     else if(znak=="s")
     {
         
          if(umisteni==6)
         {
              pozice=pozice+max;
              if(pozice<max*max)
              {
                  tedka=hrac->vrat_nacemstojim();
                  hra->hejbej_hrace(tedka,pozice-max, umisteni);
                  umisteni=0;
                  predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                     pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                        pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                
                  }
                }
              else cout<<"chybny udaj"<<endl;
         }
          else if(umisteni==7)
         {
             pozice=pozice+max;
              if(pozice<max*max)
              {
                  tedka=hrac->vrat_nacemstojim();
                  hra->hejbej_hrace(tedka,pozice-max, umisteni);
                umisteni=1;
                predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                          pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                          pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else if(umisteni==8)
         {
             pozice=pozice+max;
              if(pozice<max*max)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice-max, umisteni);
                    umisteni=2;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                      pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else
         {
                  tedka=hrac->vrat_nacemstojim();
                  hra->hejbej_hrace(tedka,pozice, umisteni);
                  umisteni=umisteni+3;
                  predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                   else
                  {
                      pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }   
         } 
     }
     else if(znak=="d")
     {
           if(umisteni==2)
         {
              pozice=pozice+1;
              if(pozice<max*max && pozice>=0)
              {
                  tedka=hrac->vrat_nacemstojim();
                  hra->hejbej_hrace(tedka,pozice-1, umisteni);
                  umisteni=0;
                  predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                          pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
                
              }
              else cout<<"chybny udaj"<<endl;
         }
          else if(umisteni==5)
         {
             pozice=pozice+1;
              if(pozice<max*max && pozice>=0)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice-1, umisteni);
                    umisteni=3;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                   else
                  {
                          pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else if(umisteni==8)
         {
             pozice=pozice+1;
              if(pozice<max*max && pozice>=0)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice-1, umisteni);
                    umisteni=6;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                      pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else
         {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice, umisteni);
                    umisteni=umisteni+1;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                     pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                   else
                  {
                     pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
         }
     }
     else if(znak=="a")
     {
         if(umisteni==0)
         {
              pozice=pozice-1;
              if(pozice<max*max && pozice>=0)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice+1, umisteni);
                    umisteni=2;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                      pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
                
              }
              else cout<<"chybny udaj"<<endl;
         }
          else if(umisteni==3)
         {
              pozice=pozice-1;
              if(pozice<max*max && pozice>=0)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice+1, umisteni);
                    umisteni=5;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                           pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else if(umisteni==6)
         {
             pozice=pozice-1;
              if(pozice<max*max && pozice>=0)
              {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice+1, umisteni);
                    umisteni=8;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                           pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
              }
              else cout<<"chybny udaj"<<endl;
         }
         else
         {
                    tedka=hrac->vrat_nacemstojim();
                    hra->hejbej_hrace(tedka,pozice, umisteni);
                    umisteni=umisteni-1;
                    predtim=hra->vrat_tvarp(pozice, umisteni);
                  if(predtim=='w')
                  {
                      pohyb_chyba(hrac,hra, vzhled[0]);
                  }
                  else
                  {
                          pohyb_prepis(hrac,hra, vzhled[0],pozice, umisteni,predtim);
                  }
             
         }
     

    
    }
         
}

//******************************************************************************
int main (void) {
    int pocet,pocet_karet,pocet_hracu,j=0,rotace,vloz,rada,vyhra=0;
    string znak;
    vector<Hrac> hraci;
    cout <<"zadej velikost hraci desky: ";
    cin>>pocet;
    cout <<"zadej pocet karet: ";
    cin>>pocet_karet;
    cout <<"zadej pocet hracu: ";
    cin>>pocet_hracu;
    vyhra=pocet_karet/pocet_hracu;
  //Deska d(20,20,11);
  //Deska d(20,20,9);
  Deska d(pocet);
  Balicek pocek(pocet_karet);
  
  vloz_kartu(&d, &pocek);
  for(int i=1;i<=pocet_hracu;i++){
  
        if(i==1)
        {
           hraci.push_back(Hrac ("1",0,0));
           rozmistit_hrace(&d, &hraci[0]);
           rozdej_karty( &hraci[0], &pocek);
        }
        
        if(i==2)
        {
           hraci.push_back(Hrac ("2",pocet-1,0));
           rozmistit_hrace(&d, &hraci[1]);
           rozdej_karty( &hraci[1], &pocek);
        }
        
        if(i==3)
        {
           hraci.push_back(Hrac ("3",pocet*pocet-pocet,0)); 
           rozmistit_hrace(&d, &hraci[2]);
           rozdej_karty( &hraci[2], &pocek);
        }
         
        if(i==4)
        {
           hraci.push_back(Hrac ("4",pocet*pocet-1,0));
           rozmistit_hrace(&d, &hraci[3]);
           rozdej_karty( &hraci[3], &pocek);
        }
        
  }
  
  cout<<"hledat predmet:"<<hraci[0].vrat_co()<<endl;
  cout<<"skore hrace: "<<hraci[0].vrat_skore()<<endl;
  d.vykreslit();
  while(znak!="q"){
      cin>>znak;
      
      if(znak=="e")
      { 
         j++;
         if(j>hraci.size()-1) j=0;
         cout<<"zadej rotaci"<<endl;
         
         cin>>rotace;
         cout<<"zadej stranu1-4"<<endl;
         cin>>vloz;
         cout<<"zadej radu"<<endl;
         cin>>rada;
         hraci=otoc(&d, vloz, rada, rotace,&pocek,hraci);
         
      }
      else if(znak=="w" || znak=="s" || znak=="a" ||znak=="d")
      {
            pohyb(&d,&hraci[j],&pocek,znak);
      }
     
      cout<<"hledat predmet:"<<hraci[j].vrat_co()<<endl;
       cout<<"skore hrace: "<<hraci[j].vrat_skore()<<endl;
      skotroluj(&hraci[j],&pocek);
      if(vyhra==hraci[j].vrat_skore())
      {
          znak="q";
         cout<<"vyhra"<<endl;
      }
      //pocek.vypis_balicek();
     d.vykreslit();
  }
  //pohyb(&d,hraci,&pocek);
  //d.vykreslit();
  //otoc(&d, 1, 1, 3);
  //d.vykreslit();
  //Policko s("L",1);
  //s.vypis();
  //d.zadej_sirka(50);
  //d.ziskej_sirka();
  return 0;
}