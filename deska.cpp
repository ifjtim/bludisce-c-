#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Policko
{
private:
    string tvar;
    
public:
    Policko(string vzhled_policka,int rotace);     //vzhled_policka L,I,T
    void vypis1();
    void vypis2();
    void vypis3();
    
};

class Deska
{
private:
    int sirka;
    int vyska;
    int pocet;
    vector<Policko> hraci_plocha;
public:
    Deska(int insirka,int inyzska,int inpocet);
    ~Deska();
    void zadej_sirka(int nasirka);
    void ziskej_sirka();
    void zadej_vyska(int navyska);
    void ziskej_vyska();
    void vykreslit();
};



 void Deska::zadej_sirka(int nasirka)
 {
    sirka=nasirka; 
 }
 
 void Deska::zadej_vyska(int navyska)
 {
    vyska=navyska; 
 }
 
 Deska::Deska(int insirka,int invyska,int inpocet)
 {
     srand (time(NULL));
     int nahodne_natoceni,nahodne_vyber;
     int d=1,rad=1,sloupec=1;
     string neco;
    vyska=invyska; 
    sirka=insirka; 
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
    cout << vypocet<< endl;
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
        cout<< nahodne_vyber<< endl;
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
 
 void Deska::ziskej_sirka()
 {
   cout << sirka<< endl;
 }
 
 Deska::~Deska()
 {
 }
 
 void Deska::ziskej_vyska()
 {
   cout << vyska<< endl;
 }
 
 void Deska::vykreslit(){
 cout << hraci_plocha.size()<< endl;
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
 
  Policko::Policko(string vzhled_policka,int rotace)
 {
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
int main (void) {
    int pocet;
    cin>>pocet;
  //Deska d(20,20,11);
  //Deska d(20,20,9);
  Deska d(20,20,pocet);
  //Deska d(20,20,5);
  d.vykreslit();
  Policko s("L",1);
  //s.vypis();
  //d.zadej_sirka(50);
  d.ziskej_sirka();
  return 0;
}