/**
 * Labirint 2015
 *
 * @author Tomasz Konderla xkonde03
 * @author Pavel Červený xcerve15
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h> 
#include <ctime>
#include "deska.h"

using namespace std;



//*****************fukce balicek *********************************************************************
    /**
    * konstrukter Balicku karet pošle se počet karet
    *
    * @param pocet je počet karet v baličku
    * 
    */
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
    
    /**
    * konstrukter2 Balicku složi pri načutani baličku z uložene hry
    *
    * @param pocet je počet karet v baličku
    * @param pozi jsou souřadnice karet na hraci desce
    * @param vlastnost jsou to informace jestli karta byla už vybrana
    * 
    * 
    */
    
     Balicek::Balicek(int pocet,vector<int> pozi,vector<string> vlastnost)
    {
        string ukol= "~!@#$%^&*()_+{}:<>?|\"qser"; //volba tvaru karty
        string vul;
        int pozic;
        for(int i=0;i<=pocet-1;i++){
           vul=ukol[i];
           pozic=pozi[i]; 
           //cout<<  i<<vul<<pozic <<endl;
        balicek_karet.push_back(Karta (vul,vlastnost[i],pozic));//posilani vlastnosti konkretni karte
            
        }
        velikost=pocet; 
    }
    
    /**
    * fukce pro vypsani baliku karet
    * 
    */ 
    
    void Balicek::vypis_balicek()
    {
        for(int i =0 ;i<=balicek_karet.size()-1;i++){
        
            balicek_karet[i].vypis(); 
        }
        
    }
    
    /**
    * vrati tvar karty
    *
    * @param pozice pozice hledane karty
    */
    
    string Balicek::vrat_kartu(int pozice)
    {
        return balicek_karet[pozice].vrat_predmet();
    }
    
    /**
    * prepise pozici karty na hraci plose poouze interni informaci co má karta
    *
    * @param pozice pozice dane karty ve vektoru
    * @param pozice pozice na hraci desce
    */
    
    void Balicek::zapispozici(int pozice,int kde)
    {
        balicek_karet[pozice].umistit(kde);
    }
    
    /**
    * vrati velikost baličku počet karet
    *
    */  
    
    int Balicek::vrat_velikost(){
    
        return velikost;
    }
    
    /**
    * vrati pozici na hraci desce podle vzhledu karty
    *
    * @param znak vzhled dane karty
    * 
    */ 
    
    int Balicek::vrat_pozici(string znak){
        int kontrola=0;
        for(int i =0 ;i<=balicek_karet.size()-1;i++){ //projede celi baliček karet
        
            kontrola=balicek_karet[i].porovnej(znak); 
            if(kontrola==1)return i;                  //pokud je dana karta hledana vrati jedna
        }
        return -1;
    }
   
    /**
    * vrati pozici ve vektoru dane karty podle toho kde se nachazi na dane hraci desce
    *
    * @param i pozice na hraci desce
    * 
    */ 
   
    int Balicek::vrat_pozici(int i){
      return balicek_karet[i].vratpozici();         
    }
   
    /**
    * přepiše že dana karta je už obsazena
    *
    * @param pozice pozice karty
    * 
    */ 
   
    void Balicek::uprav(int pozice){
       balicek_karet[pozice].prepis(); 
        
    }
    
    /**
    * vraci obsazensot kraty ano-ne
    *
    * @param i pozice karty
    * 
    */
   
    string Balicek::vrat_osazenost(int i){
      return balicek_karet[i].obsayenos(); 
        
    }
   
    /**
    * vylosuje novou kartu
    *
    * @param pozice nahodne zvolena pozice proveri a vrati vzhled karty
    * 
    */
   
    string Balicek::losuj_kartu(int pozice)
    {
        string neco="ne";
        int pocitak=0;
        while(neco=="ne"){ //proveri jestli neni obsazena
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
    
    /**
    * vrati polohu karty ve vektoru karet
    *
    * @param znak vzhled karty
    * 
    */
    
    int Balicek::vrat_polohu(string znak){
       int kontrola=-1;
        for(int i =0 ;i<=balicek_karet.size()-1;i++){
        
            kontrola=balicek_karet[i].porovnej2(znak); 
            if(kontrola!=-1)
            {
               balicek_karet[i].prepis();
                return kontrola;
            }
        }
        return -1;
    }
    
//********funkce karta**********************************************************************************    

    /**
    * konstruktor karty
    *
    * @param jake vzhled
    * 
    */
    
    Karta::Karta(string jake)
    {
        ukol=jake;
        nalezeni="ne";
    }
    
    /**
    * konstruktor karty
    *
    * @param jake vzhled
    * @param vlastnost jestli je karta nalezena 
    * @param inumisteni umisteni v hraci desce 
    * 
    */
    
    Karta::Karta(string jake,string vlastnost,int inumisteni)
    {
        ukol=jake;
        nalezeni=vlastnost;
        umisteni=inumisteni;
        //cout<<ukol<<umisteni<<nalezeni<<endl;
    }
    
     /**
    * vraci jestli karta je hledanou
    *
    * @param znak vzhled karty 
    * 
    */
    
    int Karta::porovnej(string znak){
        if(znak==ukol) return 1;
        else return -1;
    }
    
     /**
    * vraci  umisteni karty na hraci desce
    *
    * @param znak vzhled karty 
    * 
    */
    
    int Karta::porovnej2(string znak){
        if(znak==ukol) return umisteni;
        else return -1;
    }
    
     /**
    * vraci jestli umisteni karty na hraci desce
    * 
    */
    
    int Karta::vratpozici(){
         return umisteni;
       
    }
    
    /**
    * vraci obsazenost karty ano-ne
    * 
    */
    
    string Karta::obsayenos(){
         return nalezeni;
       
    }
    
     /**
    * vypis karty
    * 
    */
    
    void Karta::vypis()
    {
        cout<< ukol<<" " ;
        cout<< umisteni<<endl;
    }
    
     /**
    * vraci  umisteni karty na hraci desce
    *
    * @param pozice pizice ve vektoru
    * 
    */
    
    void Karta::umistit(int pozice){
     
        umisteni=pozice;
    }
    
    /**
    * přepiše danou kartu na to že je nalezena
    * 
    */
    
    void Karta::prepis(){
    
        nalezeni="ano";
    }
    
    /**
    * vraci  ukol karty
    * 
    */
    string Karta::vrat_predmet()
    {
        return ukol;
    }
    /**
    * vylosuje novou kartu hrači
    * 
    */
    string Karta::zapis_kartu(){
        if(nalezeni=="ne"){
        
            nalezeni="ano";
            return ukol;
        }
        else return "ne";
        
    }
    
    
//***************fukce deska***********************************************************************
 /**
    * konstruktor hraci desky pri nahravanai
    *
    * @param inpocet velikos hraci desky
    *  @param tvary string pismenek tvaru
    *  @param inpocet string rotaci
    * 
    */
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
 
 /**
    * konstruktor hraci desky
    *
    * @param inpocet velikos hraci desky
    * 
    */
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
        
        nahodne_natoceni  = rand() % 4 + 0; //hadone rotace policka
        nahodne_vyber  = rand() % 3 + 1;    //nahodny vyber polička
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
 
 /**
    * vraci velikost harci desky
    * 
    */
 
 int Deska::ziskej_pocet(){
 
     return pocet;
 }
 
  /**
    * vraci velikost vektoru harci desky
    * 
    */
 
 int Deska::ziskej_velikost(){
 
     return hraci_plocha.size();
 }

 /**
    * vraci konkretni poličko
    * 
    */
 
  Policko Deska::ziskej_policko(int pozice){
 
     return hraci_plocha[pozice];
  }

 /**
    * vykresli hraci plochu
    * 
    */
 
 void Deska::vykreslit(){
    for(int i =0 ;i<=hraci_plocha.size()-2;i+=pocet){ //postupne prvni řadu poliček
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

  /**
    * vloži nahodně předměty do hraci desky
    *
    * @param predmet tvar hledane předmětu
    *  @param pozice random poyice
    *  @param max maximalni velikost pole
    * 
    */
 
 int Deska::vloz_premety(char predmet,int pozice,int max){
    //cout<<predmet<<endl;
    int kontrola=0;
    while(kontrola!=1){
       kontrola= hraci_plocha[pozice].uprav_karta(predmet); //vraci jedna když všecjno ok jestli tam je už předmět vraci -1
       if(kontrola==1)break;
       pozice++;
       if(pozice==max)
           pozice=0;
    }
   return pozice; 
 }

 /**
    * vloži hrače na desku
    *
    * @param hrac tvar hrače
    *  @param pozice random pozice
    * 
    */
 
 void Deska::vloz_hrace(char hrac,int pozice){
    //cout<<predmet<<endl;
   hraci_plocha[pozice].uprav_hrace(hrac);

 }

  /**
    * přesune hrače po desce
    *
    * @param hrac tvar hrače
    * @param pozice ve vektoru poliček pozice
    * @param umisteni umisteni v poličku
    * 
    */
 
 void Deska::hejbej_hrace(char hrac,int pozice, int umisteni){
    //cout<<predmet<<endl;
   hraci_plocha[pozice].rozhibej_hrace(hrac,umisteni);   
 }
 
 /**
    * varti určity kus polička
    * @param pozice ve vektoru poliček pozice
    * @param umisteni umisteni v poličku
    * 
    */

 char Deska::vrat_tvarp(int pozice, int umisteni)
 {
   return hraci_plocha[pozice].vrat_policko(umisteni);
 }

 /**
    * varti vrati co se nachazi na středu polička
    * @param pozice ve vektoru poliček pozice
    * 
    */
 
 char Deska::vrat_co(int pozice)
 {
   return hraci_plocha[pozice].vrat_cotvar();
 }

 /**
    * vraci rotaci polička
    *
    * @param pozici pozice polička ve vektoru
    * 
    */
 
 int Deska::vrat_rotaci(int pozici)
 {
    return hraci_plocha[pozici].vrat_rotace();  
 }
 
 /**
    * z rotuje poličko ve vektoru
    *
    *@param pozici pozice polička ve vektoru
    * @param rotace polička
    * 
    */
 
 void Deska::prekresli_policko(int pozice,int rotace)
 {
    hraci_plocha[pozice].otoc_policko(rotace);
 }

  /**
    * vsune poličko do určiteho sloupce nabo řady
    *
    *@param pocatek na ktere pozici začina ve vektoru
    * @param kolik šiřka nebo vyška pole
    * @param karet baliček karet
    * @param hraci vektor hraču
    * 
    */
 
 
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
    
        for(int i=1;i<=pocet-1;i++){
            for(int j=0 ;j<=hraci.size()-1;j++)
            {
                hrac=hraci[j].vrat_pozici();
                if(hrac==pomocny_pocet){
                    kdo.push_back(j);
                    kam.push_back(pomocny_pocet+kolik);
                }
            }
            
            
            pomocny_pocet+=kolik;
            if(pozice_karty!=-1){
                karet->zapispozici(pozice_karty,pomocny_pocet);
            }
            pomoc=hraci_plocha[pomocny_pocet];
            kontrola=hraci_plocha[pomocny_pocet].vrat_policko(4);
            pomocnzy="";
            pomocnzy.push_back(kontrola);
            pozice_karty=karet->vrat_pozici(pomocnzy);
            hraci_plocha[pomocny_pocet]=pomoc2;
            pomoc2=pomoc;
        
        
        }
        int neco=kam.size();
        neco=neco-1;
        hraci_plocha[pocatek]=hraci_plocha[velikost-1];
        
        //umisteni karty presun
        kontrola=hraci_plocha[velikost-1].vrat_policko(4);
        pomocnzy="";
        pomocnzy.push_back(kontrola);
        pozice_karty=karet->vrat_pozici(pomocnzy);
        if(pozice_karty!=-1){
            karet->zapispozici(pozice_karty,pocatek);
        }
        hraci_plocha[velikost-1]=pomoc;
        kontrola=pomoc.vrat_policko(4);
        pomocnzy="";
        pomocnzy.push_back(kontrola);
        pozice_karty=karet->vrat_pozici(pomocnzy);
        if(pozice_karty!=-1){
            karet->zapispozici(pozice_karty,velikost-1);
        }
        //teleportin hrace
            for(int j=0 ;j<=hraci.size()-1;j++)
            {
                hrac=hraci[j].vrat_pozici();
                if(hrac==pomocny_pocet)
                {
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
            }
            for(int z=0;z<=neco;z++)
            {
                kdoo=kdo[z];
                kamm=kam[z];
                hraci[kdoo].uprav_pozici(kamm);
                }
        return hraci;
 }

//******************fukce policko**********************************************************************

/**
    * konstruktor polička
    *
    *@param vzhled_policka tvar polička L-T-I
    * @param rotace rotace polička
    * 
    */

  Policko::Policko(string vzhled_policka,int rotace)
 {
     vyznam=vzhled_policka[0];
     rotaci=rotace;
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
    
    
/**
    * vypise horni řad polička
    * */
    
 void Policko::vypis1(){
     cout << tvar[0]<<tvar[1]<<tvar[2]<<" "; 
 }
 
 /**
    * středni řad polička
    * */
 
 void Policko::vypis2(){
     cout << tvar[3]<<tvar[4]<<tvar[5]<<" "; 
 }
 
 /**
    * dolni řad polička
    * */
 
 void Policko::vypis3(){
     cout << tvar[6]<<tvar[7]<<tvar[8]<<" ";
 }
 
 /**
    * vrati určity tvar z polička
    * @param pozice umisteni v poličku
    * */

 char Policko::vrat_policko(int pozice){
     return tvar[pozice];
 }
 
 /**
    * vrati jaky druh je to poličko L-I-T
    *
    * */

 char Policko::vrat_cotvar(){
     return vyznam;
 }
 
 /**
    * vloži tam předmět pokud už tam neni
    * @param predmet vkladany předmět
    * */

 int Policko::uprav_karta(char predmet){
    if(tvar[4]=='h')
    {
        tvar[4]=predmet;
        return 1;
    }
    else return -1;
  }

  /**
    * vloži hrače do polička
    * @param hrac tvar hrače
    * */
  
  int Policko::uprav_hrace(char hrac){
    tvar[4]=hrac;
    return 1;  
  }

  /**
    * přesune hrače po poličku
    * @param hrac tvar hrače
    * @param umisteni umistěni v poličku
    * */
  void Policko::rozhibej_hrace(char hrac, int umisteni){
    tvar[umisteni]=hrac;
    
  }
  
  /**
    * vrati rotaci polička
    * */

  int Policko::vrat_rotace(){
    return rotaci;
  }

  /**
    * zrotuje poličko
    * @param rotace rotane polička
    * */
  
  void Policko::otoc_policko(int rotace){
    char stre=tvar[4];
    rotaci=rotace;
    string stred;
    stred.push_back(stre);
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
 }

//********************hrac****************************************************

/**
    * konstruktor hrače
    * @param invzhled vkladany hrač
    * @param inpozice pozice hrače
    * @param inskore skore hrače
    * */

Hrac::Hrac(string invzhled,int inpozice,int inskore){
    umisteni=4;
    vzhled=invzhled;
    pozice=inpozice;
    skore=inskore;
}

/**
    * konstruktor hrače pro načteni hry
    * @param invzhled vkladanyhrač
    * @param inpozice pozice hrače
    * @param inskore skore hrače
    * @param innacemstojim načem stal
    * @param hladani co hleda
    * 
    * */

Hrac::Hrac(string invzhled,int inpozice,int inskore,int inumisteni,char innacemstojim,string hladani){
     
    umisteni=inumisteni;
    vzhled=invzhled;
    pozice=inpozice;
    skore=inskore;
    nacemstojim=innacemstojim;
    co=hladani;
}

 /**
    * vrati tvar hrače
    * 
    * */

string Hrac::vrat_hrace()
{
    return vzhled;
}

/**
    * vypiše hrače
    * 
    * */

void Hrac::vypis()
{
    cout<<"hrac"<<pozice<<endl;
}

/**
    * upravi pozici hrače
    * @param upozice pozice hrače
    * 
    * */

void Hrac::uprav_pozici(int upozice)
{
    pozice=upozice;
}

/**
    * upravi umisteni hrače
    * @param uumisteni umisteni hrače
    * 
    * */

void Hrac::uprav_umisteni(int uumisteni)
{
    umisteni=uumisteni;
}

/**
    * vraci pozici hrače
    * 
    * */

int Hrac::vrat_pozici()
{
 return pozice;   
}

/**
    * vraci umisteni hrače
    * 
    * */

int Hrac::vrat_umisteni()
{
 return umisteni;   
}

/**
    * vraci načem stoji hrač
    * 
    * */

char Hrac::vrat_nacemstojim()
{
 return nacemstojim;   
}

/**
    * vraci co hleda hrač
    * 
    * */

string Hrac::vrat_co()
{
 return  co;  
}

/**
    * vraci skore hrače
    * 
    * */

int Hrac::vrat_skore()
{
 return  skore;   
}



int Hrac::vrat_kde()
{
 return  kde;   
}
/**
    * prepiše hledanou věc
    * @param coo nova hledana věc
    * 
    * */
void Hrac::zapis_co(string coo)
{
   co=coo; 
}

/**
    * přičte skore
    * @param skoree nove skore
    * 
    * */


void Hrac::zapis_skore(int skoree)
{
  skore=skore+skoree;  
}



void Hrac::zapis_kde(int kdee)
{
   kde=kdee;
    
}

/**
    * přepiše na čem stoji
    * @param tvarek nová věc na ktere hrač stoji
    * 
    * */

void Hrac::zapis_nacemstojim(char tvarek)
{
    nacemstojim=tvarek;
}
/***********funkce**********************************************************/

/**
    * uloži hru
    * @param hra hraci deska
    * @param karet baliček karet
    * @param hraci vektor hraču
    * @param jmeno jmeno souboru
    * @param aktualnihrac ktery hrač hraje
    * 
    * */


void uloz_hru(Deska *hra,  Balicek *karet,vector<Hrac> hraci,string jmeno,int aktualnihrac){
    
    int pocet=hra->ziskej_pocet(),pocet_karet=karet->vrat_velikost(),pocet_hrac=hraci.size();
    FILE *soubor;
    string ano,vzhled,hledani;
    char  nascem;
    char *cstr = new char[jmeno.length() + 1];
    strcpy(cstr, jmeno.c_str());

    soubor = fopen(cstr, "w");
    if(soubor==NULL) 
    {
        cout<<"chybny   soubor"<<endl;
       return ;
    }
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
    }
    fprintf(soubor, "\n");
    
    for(int j=0;j<=pocet_karet-1;j++)
    {
         ano=karet->vrat_osazenost(j);
         char *neco = new char[ano.length() + 1];
         strcpy(neco, ano.c_str());
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

/**
    * uloži hru pro autosave
    * @param hra hraci deska
    * @param karet baliček karet
    * @param hraci vektor hraču
    * @param jmeno atribut zapis
    * @param aktualnihrac ktery hrač hraje
    * 
    * */

void uloz_hru_autosave(Deska *hra,  Balicek *karet,vector<Hrac> hraci,string jmeno,int aktualnihrac){
    
    int pocet=hra->ziskej_pocet(),pocet_karet=karet->vrat_velikost(),pocet_hrac=hraci.size();
    FILE *soubor;
    string ano,vzhled,hledani;
    char  nascem;
    char *cstr = new char[jmeno.length() + 1];
    strcpy(cstr, jmeno.c_str());

    soubor = fopen("autosave.txt", cstr);
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
         //cout<<karet->vrat_pozici(i)<<endl;
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
       //fprintf(soubor, "\n"); 
fclose(soubor);
delete [] cstr;    
}

/**
    * rozloži karty po hraci desce
    * @param hra hraci deska
    * @param karet baliček karet
    * 
    * */

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
        ukarta=co->vrat_kartu(i);
        vrat_p=hra->vloz_premety(ukarta[0],nahodne_umisteni,velikost);
        co->zapispozici( i, vrat_p);  
    }
}

void vloz_kartu2(Deska *hra, Balicek *co){
    string ukarta;
    int pos;
    for (int i=0;i<=co->vrat_velikost()-1;i++){
        ukarta=co->vrat_kartu(i);
        pos=co->vrat_pozici(i);
        hra->hejbej_hrace(ukarta[0],pos, 4);   
    }
}
   
   /**
    * hlida hrače jestli nenašel hledany předmět
    * @param karet baliček karet
    * @param hrac konkretni hrač
    * 
    * */
   
void skotroluj(Hrac *hrac, Balicek *co){
    string hledany;
    int pozice_hledaneho,pozice_hrace;
    hledany=hrac->vrat_co();
    pozice_hledaneho=co->vrat_polohu(hledany);
    pozice_hrace=hrac->vrat_pozici();
    if(pozice_hledaneho==pozice_hrace){
        hrac->zapis_skore(1);
        rozdej_karty(hrac,co); 
    }   
}

/**
    * rozděli karty hračum
    * @param karet baliček karet
    * @param hrac konkretni hrač
    * */
   
void rozdej_karty(Hrac *hrac, Balicek *co){
    string ukarta;
    int  nahodne_umisteni,veli=co->vrat_velikost() ;
    srand (time(NULL));
    nahodne_umisteni  = rand() % veli + 0;
    ukarta=co->losuj_kartu(nahodne_umisteni);
    hrac->zapis_co(ukarta);   
}

/**
    * zrotuje poličko a vloži do hraci desky
    * @param hra hraci deska
    * @param strana vyber strany
    * @param rada vyber řady
    * @param rotace rotace polička
    * @param karet baliček karet 
    * @param hraci vektor hraču
    * 
    * */

vector<Hrac> otoc(Deska *hra, int strana, int rada, int rotace, Balicek *karet,vector<Hrac> hraci){
     int velikost,pocet,pomocny;
    // Policko pomocne;
   
    velikost=hra->ziskej_velikost();
    velikost-=1;
    pocet=hra->ziskej_pocet();
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
    
    return hraci;
}

/**
    * rozmisti hrače po poli
    * @param hra herni deska
    * @param hrac konkretni hrač
    * */

void rozmistit_hrace(Deska *hra, Hrac *hrac){
    int pozice;
    string vzhled;
    char cotam;
   
    
        vzhled=hrac->vrat_hrace();
        pozice=hrac->vrat_pozici();
        cotam=hra->vrat_tvarp(pozice, 4);
        hrac->zapis_nacemstojim(cotam);
        hra->vloz_hrace(vzhled[0],pozice);
         
}
 
 
//posna fukce pohybu
inline void pohyb_prepis(Hrac *hrac,Deska *hra,  char vzhled,int pozice, int umisteni,char predtim){
                    hrac->zapis_nacemstojim(predtim);
                    hrac->uprav_pozici(pozice);
                    hrac->uprav_umisteni(umisteni);
                    hra->hejbej_hrace(vzhled,pozice, umisteni);
                    
}

//pomocna fukce pohybu
inline void pohyb_chyba(Hrac *hrac,Deska *hra,  char vzhled){
    int umisteni,pozice;
                    cout<<"spatny tah"<<endl;
                      pozice=hrac->vrat_pozici();
                      umisteni=hrac->vrat_umisteni();
                      
                    hra->hejbej_hrace(vzhled,pozice, umisteni);
                    
}
/**
    * zajiščuje pohyb hraču po hraci desce
    * @param hra hraci deska
    * @param hrac konkretni hrač
    * @param karty baliček karet
    * @param znak zmačknuta klavesnice pohybu
    * */

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
