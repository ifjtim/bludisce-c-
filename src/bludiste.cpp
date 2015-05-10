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



int main (void) {
    int pocet,pocet_karet,pocet_hracu,tah=0,rotace,vloz,rada,vyhra=0,porvykr=0,kroky=1;
    string znak,nacist,jmeno_hry,nacata,prepast;
    
    vector<Hrac> hraci;
    Deska *d;
    Balicek *pocek;
    Policko pomocne1("w",1),pomocne2("w",1),pomocne3("w",1),pomocne4("w",1);
    cout <<"nacist hru ano ne: ";
    cin>>nacist;
    if(nacist=="ano") //vyběr načteni hry
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

                soubor = fopen(cstr, "r");                
                delete [] cstr;
                if(soubor==NULL) {
                 cout<<"chybne jmeno"<<endl;
                 return 1;
                }
                fscanf(soubor, "%d", &num);
                pocet=num;
                neco=fgetc(soubor);
                //pismenka L-T-I tvary
                neco= fgetc (soubor);
                do{
                    covlastne.push_back(neco);
                    neco= fgetc (soubor);
                    
                    }while (neco != '\n');
           
                neco= fgetc (soubor);
                
                //rotace policek
                do{
                    rotace.push_back(neco);
                    neco= fgetc (soubor);
                }while (neco != '\n');
                
                //pocet karet
                pocett[0]= fgetc (soubor);
                pocett[1]= fgetc (soubor);
                pocett[2]= '\0';
                pocet_ka = atoi (pocett);
                 // souradnice karet
                neco= fgetc (soubor);
                neco= fgetc (soubor);
                for(int i=0;i<=pocet_ka-1;i++)
                {
                    
                    do{
                    umisteni_karet[ci]= neco;
                    neco= fgetc (soubor);
                    ci++;
                    
                    }while (neco != '\n' && neco !=' ');
                    umisteni_karet[ci]='\0';
                    ci=0;
                    pozicc= atoi (umisteni_karet);
                    pozi.push_back(pozicc);
                }
                //vlastnosti ano-ne
                neco= fgetc (soubor);
                neco= fgetc (soubor);
                for(int i=0;i<=pocet_ka-1;i++)
                {
                    
                    do{
                    anone.push_back(neco);
                    neco= fgetc (soubor);
                    
                    }while (neco != '\n' && neco !=' ');
                    
                    vlastnost.push_back(anone);
                    neco= fgetc (soubor);
                    //cout<<"umi"<<anone<<"umi"<<endl;
                    anone="";
                }
                //tvoreni instanci
                d=new Deska(num,covlastne,rotace);
                pocek=new Balicek(pocet_ka,pozi, vlastnost);
                 //vloyeni karet
                vloz_kartu2(d, pocek);

                neco= fgetc (soubor);
                pocet_h=int(neco);
                pocet_h=pocet_h-48;
                neco= fgetc (soubor);
                pocet_hracu=pocet_h;
                pocet_karet=pocet_ka;
                
                //nacitani hracu
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
                    }
                    neco= fgetc (soubor);
                    hraci.push_back(Hrac (vzhled_h,pos_h,skore_h,umis_h,stol[0],hladani)); 
                            d->hejbej_hrace(vzhled_h[0],pos_h,umis_h);
                            //rozdej_karty( &hraci[i], pocek);
                }
                
                //aktualni pozice
                neco= fgetc (soubor);
                tah=int(neco);
                tah=tah-48;
                fclose(soubor);
            
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
    
    
    
  
  cout<<"hledat predmet:"<<hraci[0].vrat_co()<<endl; //vypis hledanehp
  cout<<"skore hrace: "<<hraci[0].vrat_skore()<<endl; //skore hrače
  vyhra=pocet_karet/pocet_hracu;
  d->vykreslit();
  uloz_hru_autosave(d,pocek, hraci,"w",tah);
  while(znak!="q"){
      
      cin>>znak;//nacetni pokynu
     //autosave
      if(znak=="z" )
      {

                            FILE *soubor;
                            int num,pocet_ka,ci=0,pozicc,pocet_h=0,pos_h=0,umis_h=0,skore_h=0,vypoce=0;
                            char neco,pocett[3],umisteni_karet[10],hrac[4];
                            string covlastne,rotace,anone,vzhled_h,stol,hladani;
                            vector<int> pozi;
                            vector<string> vlastnost;
                            
                            
                            
                                soubor = fopen("autosave.txt", "r");
                                
                                
                                if(soubor==NULL) {
                                cout<<"chybne jmeno"<<endl;
                                return 1;
                                }
                   
                   
                   for(int jogo=1;jogo<=kroky;jogo++){
                        while (!hraci.empty()) // Opakuj, dokud není prázdný (Dokud nemá 0 prvků )
                        {
                            hraci.pop_back(); // Odeberu poslední prvek
                        }
                         
                        
                        delete d;
                        delete pocek;
                               
                                neco=fgetc(soubor);
                                prepast.push_back(neco);
                                num=int(neco);
                                 num=num-48;
                                pocet=num;
                                ////cout<<num<<endl;
                                neco=fgetc(soubor);
                                prepast.push_back(neco);
                                //cout<<"1"<<neco<<endl;
                                neco= fgetc (soubor);prepast.push_back(neco);
                                prepast.push_back(neco);
                            do{
                                covlastne.push_back(neco);
                                neco= fgetc (soubor);prepast.push_back(neco);
                                
                                }while (neco != '\n');
                                
                                //cout<<covlastne<<endl;
                                
                                neco= fgetc (soubor);prepast.push_back(neco);
                            do{
                                rotace.push_back(neco);
                                neco= fgetc (soubor);prepast.push_back(neco);
                                
                                }while (neco != '\n');
                                
                                //cout<<rotace<<endl;
                                //neco= fgetc (soubor);prepast.push_back(neco);
                                pocett[0]= fgetc (soubor);
                                pocett[1]= fgetc (soubor);
                                pocett[2]= '\0';
                                pocet_ka = atoi (pocett);
                                prepast.push_back(pocett[0]);
                                 prepast.push_back(pocett[1]);
                                //cout<<pocett<<"dd"<<endl;
                                //cout<< pocet_ka <<"dd"<<endl;
                                neco= fgetc (soubor);prepast.push_back(neco);
                                neco= fgetc (soubor);prepast.push_back(neco);
                                for(int i=0;i<=pocet_ka-1;i++)
                                {
                                    
                                    do{
                                    umisteni_karet[ci]= neco;
                                // cout<<neco<<endl;
                                    neco= fgetc (soubor);prepast.push_back(neco);
                                    ci++;
                                    
                                    }while (neco != '\n' && neco !=' ');
                                    umisteni_karet[ci]='\0';
                                    ci=0;
                                    pozicc= atoi (umisteni_karet);
                                    pozi.push_back(pozicc);
                                    //cout<<umisteni_karet<<"umi"<<endl;
                                }
                                neco= fgetc (soubor);prepast.push_back(neco);
                                neco= fgetc (soubor);prepast.push_back(neco);
                                for(int i=0;i<=pocet_ka-1;i++)
                                {
                                    
                                    do{
                                    anone.push_back(neco);
                                    neco= fgetc (soubor);prepast.push_back(neco);
                                    
                                    }while (neco != '\n' && neco !=' ');
                                    
                                    vlastnost.push_back(anone);
                                    neco= fgetc (soubor);prepast.push_back(neco);;
                                    anone="";
                                }
                                
                                d=new Deska(num,covlastne,rotace);
                                pocek=new Balicek(pocet_ka,pozi, vlastnost);
                                    //vloyeni karet
                                vloz_kartu2(d, pocek);
                                    neco= fgetc (soubor);
                                    prepast.push_back(neco);
                                    pocet_h=int(neco);
                                    pocet_h=pocet_h-48;
                                    neco= fgetc (soubor);
                                    prepast.push_back(neco);

                                    pocet_hracu=pocet_h;
                                    pocet_karet=pocet_ka;
                                for(int i=0;i<=pocet_h-1;i++)
                                {
                                    for(int j=0;j<=5;j++)
                                    {
                                            ci=0;
                                            do{
                                        
                                                neco= fgetc (soubor);prepast.push_back(neco);
                                                
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
                                    neco= fgetc (soubor);prepast.push_back(neco);
                                    
                                    //cout<<vzhled_h<<" "<<pos_h<<"  "<<umis_h<<" "<<skore_h<<" "<<stol<<"hh"<<endl;
                                    hraci.push_back(Hrac (vzhled_h,pos_h,skore_h,umis_h,stol[0],hladani)); 
                                            d->hejbej_hrace(vzhled_h[0],pos_h,umis_h);
                                            //rozdej_karty( &hraci[i], pocek);
                                }
                                
                                neco= fgetc (soubor);
                                prepast.push_back(neco);
                                
                                //neco= fgetc (soubor);prepast.push_back(neco);
                                tah=int(neco);
                                tah=tah-48;
                                vypoce=jogo;
                                    //cout<<j<<"cislo_hracu"<<endl;
                                
                               d->vykreslit();
          }
          //cout<<prepast<<endl;  
           fclose(soubor);
           int vypocet=prepast.size()/vypoce;
           vypocet=prepast.size()-vypocet;
           if(vypocet>0)//jesce prepsat chyba
           {
                    string kravina;
                    for(int jo=0;jo<=vypocet-1;jo++){

                        kravina.push_back(prepast[jo]);

                    }
                    prepast="";
                    
                    char *shoj = new char[kravina.length() ];
                        strcpy(shoj, kravina.c_str());
                        cout<<shoj<<endl;
                        soubor = fopen("autosave.txt", "w");
                        fprintf(soubor, "%s ",shoj);
                        fclose(soubor);
                        delete []shoj;
                        kravina="";
           }
          
          kroky--;
          if(kroky==0)kroky=1;
            continue;
   
      }
      
       else if(znak=="e")
      { 
         kroky++;
         tah++;
         if(tah>hraci.size()-1) tah=0;
         uloz_hru_autosave(d,pocek, hraci,"a",tah);
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

     d->vykreslit();
  }

  return 0;
}