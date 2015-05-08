#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h> 
#include "deska.h"

using namespace std;
/*
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
};*/

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
    
     Balicek::Balicek(int pocet,vector<int> pozi,vector<string> vlastnost)
    {
        string ukol= "~!@#$%^&*()_+{}:<>?|\"qser";
        string vul;
        int pozic;
        //cout <<" c    sfeasdjfheauisgvdb  "<<pocet <<endl;
        for(int i=0;i<=pocet-1;i++){
           vul=ukol[i];
           pozic=pozi[i]; 
           //cout<<  i<<vul<<pozic <<endl;
        balicek_karet.push_back(Karta (vul,vlastnost[i],pozic));
            
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
   
   int Balicek::vrat_pozici(int i){
      return balicek_karet[i].vratpozici(); 
        
   }
   
   void Balicek::uprav(int pozice){
       balicek_karet[pozice].prepis(); 
        
   }
   
    string Balicek::vrat_osazenost(int i){
      return balicek_karet[i].obsayenos(); 
        
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
    
     Karta::Karta(string jake,string vlastnost,int inumisteni)
    {
        ukol=jake;
        nalezeni=vlastnost;
        umisteni=inumisteni;
        //cout<<ukol<<umisteni<<nalezeni<<endl;
    }
    
    
    int Karta::porovnej(string znak){
        if(znak==ukol) return 1;
        else return -1;
    }
    
    int Karta::porovnej2(string znak){
        if(znak==ukol) return umisteni;
        else return -1;
    }
    
    int Karta::vratpozici(){
         return umisteni;
       
    }
    
    string Karta::obsayenos(){
         return nalezeni;
       
    }
    
    void Karta::vypis()
    {
        cout<< ukol<<" " ;
        cout<< umisteni<<endl;
    }
    void Karta::umistit(int pozice){
     
        umisteni=pozice;
    }
    
    void Karta::prepis(){
    
        nalezeni="ano";
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
 Deska::Deska(int inpocet, string tvary, string rotaci)
 {
     int cislo;
     pocet=inpocet;
     char neco1,neco2;
     string achjo;
     for(int i=0; i<=(inpocet*inpocet);i++){
         neco1=rotaci[i];
         neco2=tvary[i];
          achjo="";
         achjo.push_back(neco2);
         cislo=int(neco1);
         cislo=cislo-48;
         //cout<<achjo<<cislo<<endl;
        hraci_plocha.push_back(Policko (achjo,cislo));
     }
 }
 
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

Policko Deska::ziskej_policko(int pozice){
 
     return hraci_plocha[pozice];
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

char Deska::vrat_co(int pozice)
{
   return hraci_plocha[pozice].vrat_cotvar();
}

int Deska::vrat_rotaci(int pozici)
{
  return hraci_plocha[pozici].vrat_rotace();  
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
     rotaci=rotace;
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

char Policko::vrat_cotvar(){
     return vyznam;
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

int Policko::vrat_rotace(){
 
    return rotaci;
    
}

void Policko::otoc_policko(int rotace){
    char stre=tvar[4];
    rotaci=rotace;
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

Hrac::Hrac(string invzhled,int inpozice,int inskore,int inumisteni,char innacemstojim,string hladani){
     umisteni=inumisteni;
    vzhled=invzhled;
    pozice=inpozice;
    skore=inskore;
    nacemstojim=innacemstojim;
    co=hladani;
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
void uloz_hru(Deska *hra,  Balicek *karet,vector<Hrac> hraci,string jmeno,int aktualnihrac){
    
    int pocet=hra->ziskej_pocet(),pocet_karet=karet->vrat_velikost(),pocet_hrac=hraci.size();
    FILE *soubor;
    string ano,vzhled,hledani;
    char  nascem;
    char *cstr = new char[jmeno.length() + 1];
    strcpy(cstr, jmeno.c_str());

    soubor = fopen(cstr, "w");
    fprintf(soubor, "%d\n",pocet);
    for(int i=0;i<=(pocet*pocet);i++){
       fprintf(soubor, "%c",hra->vrat_co(i)); 
        
    }
    fprintf(soubor, "\n"); 
    
    for(int i=0;i<=(pocet*pocet);i++){
       fprintf(soubor, "%d",hra->vrat_rotaci(i)); 
        
    }
    fprintf(soubor, "\n"); 
     fprintf(soubor, "%d\n",pocet_karet);
     
     for(int i=0;i<=pocet_karet-1;i++)
     {
         fprintf(soubor, "%d ",karet->vrat_pozici(i));
         cout<<karet->vrat_pozici(i)<<endl;
     }
     fprintf(soubor, "\n"); 
     for(int j=0;j<=pocet_karet-1;j++)
     {
         ano=karet->vrat_osazenost(j);
         char *neco = new char[ano.length() + 1];
            strcpy(neco, ano.c_str());
        //cout<<ano<<endl;
         fprintf(soubor, "%s ",neco);
          
         delete [] neco;
     }
     
     fprintf(soubor, "\n");
     fprintf(soubor, "%d\n",pocet_hrac);
     for(int j=0;j<=pocet_hrac-1;j++){
        vzhled=hraci[j].vrat_hrace();      
        char *neco = new char[vzhled.length() + 1];
        strcpy(neco, vzhled.c_str());
        fprintf(soubor, "%s ",neco);
        fprintf(soubor, "%d ",hraci[j].vrat_pozici());
        fprintf(soubor, "%d ",hraci[j].vrat_umisteni());
        fprintf(soubor, "%d ",hraci[j].vrat_skore());
        
        nascem=hraci[j].vrat_nacemstojim();
         fprintf(soubor, "%c ",nascem);
         hledani=hraci[j].vrat_co();
         fprintf(soubor, "%c ",hledani[0]);
            fprintf(soubor, "\n");   
     }
       fprintf(soubor, "%d",aktualnihrac);  
fclose(soubor);
delete [] cstr;    
}



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

void vloz_kartu2(Deska *hra, Balicek *co){
    string ukarta;
    int pos;
    for (int i=0;i<=co->vrat_velikost()-1;i++){
        ukarta=co->vrat_kartu(i);
        pos=co->vrat_pozici(i);
    hra->hejbej_hrace(ukarta[0],pos, 4);
    //cout<<"karta "<<ukarta[0]<<" "<<i<<" "<<pos<<endl;
         
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
        co->uprav(pozice_hledaneho);
        
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
     int velikost,pocet,pomocny;
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
       
        rada=rada+1;
        rada=rada*pocet;
        rada=rada-1;
        hraci=hra->vsunot(rada,-1,karet,hraci);
    }
     else if(strana==3)
    {
        pomocny=pocet;
        pocet=pocet-pocet-pocet;
        //cout<<"bugi"<<pocet<<endl;
        pomocny=pomocny*(pomocny-1);
        rada=pomocny+rada;
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,pocet,karet,hraci);
    }
    
     else if(strana==4)
    {
        rada=rada*pocet;
        hra->prekresli_policko(velikost,rotace);
        hraci=hra->vsunot(rada,1,karet,hraci);
    }
    //karet->vypis_balicek();
    
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
    int pocet,pocet_karet,pocet_hracu,tah=0,rotace,vloz,rada,vyhra=0,porvykr=0;
    string znak,nacist,jmeno_hry,nacata;
    
    vector<Hrac> hraci;
    Deska *d;
    Balicek *pocek;
    Policko pomocne1("w",1),pomocne2("w",1),pomocne3("w",1),pomocne4("w",1);
    cout <<"nacist hru ano ne: ";
    cin>>nacist;
    if(nacist=="ano")
    {
        cout<<"zadej hru"<<endl;
        cin>>nacata;
                    FILE *soubor;
                int num,pocet_ka,ci=0,pozicc,pocet_h=0,pos_h=0,umis_h=0,skore_h=0;
            char neco,pocett[3],umisteni_karet[10],hrac[4];
            string covlastne,rotace,anone,vzhled_h,stol,hladani;
            vector<int> pozi;
            vector<string> vlastnost;
            
            
            char *cstr = new char[nacata.length() + 1];
            strcpy(cstr, nacata.c_str());
// do stuff
            
                soubor = fopen(cstr, "r");
                
                delete [] cstr;
                if(soubor==NULL) {
                 cout<<"chybne jmeno"<<endl;
                 return 1;
                }
                fscanf(soubor, "%d", &num);
                pocet=num;
                ////cout<<num<<endl;
                neco=fgetc(soubor);
                //cout<<"1"<<neco<<endl;
                neco= fgetc (soubor);
            do{
                covlastne.push_back(neco);
                neco= fgetc (soubor);
                
                }while (neco != '\n');
                
                //cout<<covlastne<<endl;
                
                neco= fgetc (soubor);
            do{
                rotace.push_back(neco);
                neco= fgetc (soubor);
                
                }while (neco != '\n');
                
                //cout<<rotace<<endl;
                //neco= fgetc (soubor);
                pocett[0]= fgetc (soubor);
                pocett[1]= fgetc (soubor);
                pocett[2]= '\0';
                pocet_ka = atoi (pocett);
                //cout<<pocett<<"dd"<<endl;
                //cout<< pocet_ka <<"dd"<<endl;
                neco= fgetc (soubor);
                neco= fgetc (soubor);
                for(int i=0;i<=pocet_ka-1;i++)
                {
                    
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
                
                d=new Deska(num,covlastne,rotace);
                pocek=new Balicek(pocet_ka,pozi, vlastnost);
                    //vloyeni karet
                vloz_kartu2(d, pocek);
                
                /*hraci.push_back(Hrac ("4",pocet*pocet-1,0));
                            rozmistit_hrace(d, &hraci[3]);
                            rozdej_karty( &hraci[3], pocek);*/
                // neco= fgetc (soubor);
                    neco= fgetc (soubor);
                    //cout<<neco<<"cislo_hracu"<<endl;
                    pocet_h=int(neco);
                    pocet_h=pocet_h-48;
                    neco= fgetc (soubor);
                    //cout<<neco<<" xhv"<<endl;
                    pocet_hracu=pocet_h;
                    pocet_karet=pocet_ka;
                for(int i=0;i<=pocet_h-1;i++)
                {
                    for(int j=0;j<=pocet_h+1;j++)
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
                    hraci.push_back(Hrac (vzhled_h,pos_h,skore_h,umis_h,stol[0],hladani)); 
                            d->hejbej_hrace(vzhled_h[0],pos_h,umis_h);
                            //rozdej_karty( &hraci[i], pocek);
                }
                
                neco= fgetc (soubor);
                //neco= fgetc (soubor);
                tah=int(neco);
                tah=tah-48;
                
                    //cout<<j<<"cislo_hracu"<<endl;
                fclose(soubor);
                //d->vykreslit();
    
    
            
    }
    else
    {
            cout <<"zadej velikost hraci desky: ";
             cin>>pocet;
             if(pocet==5||pocet==7||pocet==9||pocet==11)
                cout <<pocet <<endl;
            else pocet=7;
            cout <<"zadej pocet karet: ";
            cin>>pocet_karet;
            if(pocet_karet==24||pocet_karet==12)
                cout <<pocet<<endl;
            else pocet_karet=12; 
            cout <<"zadej pocet hracu: ";
            cin>>pocet_hracu;
            if(pocet_hracu==2||pocet_hracu==3||pocet_hracu==4)
                cout <<pocet_hracu <<endl;
            else pocet_hracu=2; 
           
        //vytvoreni desky
        
         d=new Deska(pocet);
        //vytvoreni balicku
        pocek=new Balicek(pocet_karet);
        //vloyeni karet
        vloz_kartu(d, pocek);
        //inicialiyace hracu
        for(int i=1;i<=pocet_hracu;i++){
        
                if(i==1)
                {
                hraci.push_back(Hrac ("1",0,0));
                rozmistit_hrace(d, &hraci[0]);
                rozdej_karty( &hraci[0], pocek);
                }
                
                if(i==2)
                {
                hraci.push_back(Hrac ("2",pocet-1,0));
                rozmistit_hrace(d, &hraci[1]);
                rozdej_karty( &hraci[1], pocek);
                }
                
                if(i==3)
                {
                hraci.push_back(Hrac ("3",pocet*pocet-pocet,0)); 
                rozmistit_hrace(d, &hraci[2]);
                rozdej_karty( &hraci[2], pocek);
                }
                
                if(i==4)
                {
                hraci.push_back(Hrac ("4",pocet*pocet-1,0));
                rozmistit_hrace(d, &hraci[3]);
                rozdej_karty( &hraci[3], pocek);
                }
                
        }
        
    }
    
    
    
  
  cout<<"hledat predmet:"<<hraci[0].vrat_co()<<endl;
  cout<<"skore hrace: "<<hraci[0].vrat_skore()<<endl;
   vyhra=pocet_karet/pocet_hracu;
  d->vykreslit();
  uloz_hru(d,pocek, hraci,"autosave.txt",tah);
  while(znak!="q"){
      
      cin>>znak;
      
      if(znak=="e")
      { 
         tah++;
         if(tah>hraci.size()-1) tah=0;
         uloz_hru(d,pocek, hraci,"autosave.txt",tah);
         porvykr=pocet*pocet;
         pomocne1=d->ziskej_policko(porvykr);
         pomocne2=d->ziskej_policko(porvykr);
         pomocne3=d->ziskej_policko(porvykr);
         pomocne4=d->ziskej_policko(porvykr);
         cout<<"-0- -1- -2- -3 -"<<endl;
         pomocne1.otoc_policko(0);
         pomocne2.otoc_policko(1);
         pomocne3.otoc_policko(2);
         pomocne4.otoc_policko(3);
         pomocne1.vypis1();
         pomocne2.vypis1();
         pomocne3.vypis1();
         pomocne4.vypis1();
         cout<<endl;
         pomocne1.vypis2();
         pomocne2.vypis2();
         pomocne3.vypis2();
         pomocne4.vypis2();
         cout<<endl;
         pomocne1.vypis3();
         pomocne2.vypis3();
         pomocne3.vypis3();
         pomocne4.vypis3();
         cout<<endl;
         cout<<"zadej rotaci 0 1 2 3"<<endl;
         cin>>rotace;
         if(rotace==0||rotace==1||rotace==2||rotace==3)
             cout <<rotace<<endl;
         else rotace=0;
         cout<<"zadej stranu1-4"<<endl;
         cin>>vloz;
         if(vloz==4||vloz==1||vloz==2||vloz==3)
             cout <<vloz<<endl;
         else vloz=1;
         cout<<"zadej radu"<<endl;
         cin>>rada;
         if(rada%2==0 &&rada<pocet){
             
             cout <<rada<<endl;
             rada=rada-1;
         }
         else rada=1;
         hraci=otoc(d, vloz, rada, rotace,pocek,hraci);
         
      }
      
       else if(znak=="z" )
      {
          delete d;
          delete pocek;
          while (!hraci.empty()) // Opakuj, dokud není prázdný (Dokud nemá 0 prvků )
          {
                hraci.pop_back(); // Odeberu poslední prvek
            }
                FILE *soubor;
                        int num,pocet_ka,ci=0,pozicc,pocet_h=0,pos_h=0,umis_h=0,skore_h=0;
                    char neco,pocett[3],umisteni_karet[10],hrac[4];
                    string covlastne,rotace,anone,vzhled_h,stol,hladani;
                    vector<int> pozi;
                    vector<string> vlastnost;
                    
                    
                    
                        soubor = fopen("autosave.txt", "r");
                        
                        
                        if(soubor==NULL) {
                        cout<<"chybne jmeno"<<endl;
                        return 1;
                        }
                        fscanf(soubor, "%d", &num);
                        pocet=num;
                        ////cout<<num<<endl;
                        neco=fgetc(soubor);
                        //cout<<"1"<<neco<<endl;
                        neco= fgetc (soubor);
                    do{
                        covlastne.push_back(neco);
                        neco= fgetc (soubor);
                        
                        }while (neco != '\n');
                        
                        //cout<<covlastne<<endl;
                        
                        neco= fgetc (soubor);
                    do{
                        rotace.push_back(neco);
                        neco= fgetc (soubor);
                        
                        }while (neco != '\n');
                        
                        //cout<<rotace<<endl;
                        //neco= fgetc (soubor);
                        pocett[0]= fgetc (soubor);
                        pocett[1]= fgetc (soubor);
                        pocett[2]= '\0';
                        pocet_ka = atoi (pocett);
                        //cout<<pocett<<"dd"<<endl;
                        //cout<< pocet_ka <<"dd"<<endl;
                        neco= fgetc (soubor);
                        neco= fgetc (soubor);
                        for(int i=0;i<=pocet_ka-1;i++)
                        {
                            
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
                        
                        d=new Deska(num,covlastne,rotace);
                        pocek=new Balicek(pocet_ka,pozi, vlastnost);
                            //vloyeni karet
                        vloz_kartu2(d, pocek);
                        
                        /*hraci.push_back(Hrac ("4",pocet*pocet-1,0));
                                    rozmistit_hrace(d, &hraci[3]);
                                    rozdej_karty( &hraci[3], pocek);*/
                        // neco= fgetc (soubor);
                            neco= fgetc (soubor);
                            //cout<<neco<<"cislo_hracu"<<endl;
                            pocet_h=int(neco);
                            pocet_h=pocet_h-48;
                            neco= fgetc (soubor);
                            //cout<<neco<<" xhv"<<endl;
                            pocet_hracu=pocet_h;
                            pocet_karet=pocet_ka;
                        for(int i=0;i<=pocet_h-1;i++)
                        {
                            for(int j=0;j<=pocet_h+1;j++)
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
                            hraci.push_back(Hrac (vzhled_h,pos_h,skore_h,umis_h,stol[0],hladani)); 
                                    d->hejbej_hrace(vzhled_h[0],pos_h,umis_h);
                                    //rozdej_karty( &hraci[i], pocek);
                        }
                        
                        neco= fgetc (soubor);
                        //neco= fgetc (soubor);
                        tah=int(neco);
                        tah=tah-48;
                        
                            //cout<<j<<"cislo_hracu"<<endl;
                        fclose(soubor);
                        d->vykreslit();
            continue;
   
      }
      
      
      
      
       else if(znak=="u" )
      {
          cout<<"jmeno hry:"<<endl;
          cin>>jmeno_hry;
            uloz_hru(d,pocek, hraci,jmeno_hry,tah);
      }
      else if(znak=="w" || znak=="s" || znak=="a" ||znak=="d")
      {
            pohyb(d,&hraci[tah],pocek,znak);
      }
     
      cout<<"hledat predmet:"<<hraci[tah].vrat_co()<<endl;
       cout<<"skore hrace: "<<hraci[tah].vrat_skore()<<endl;
      skotroluj(&hraci[tah],pocek);
      if(vyhra==hraci[tah].vrat_skore())
      {
          znak="q";
         cout<<"vyhra"<<endl;
      }
      
      //pocek->vypis_balicek();
     d->vykreslit();
  }
  //pohyb(d,hraci,pocek);
  //d->vykreslit();
  //otoc(d, 1, 1, 3);
  //d->vykreslit();
  //Policko s("L",1);
  //s.vypis();
  //d->zadej_sirka(50);
  //d->ziskej_sirka();
  return 0;
}