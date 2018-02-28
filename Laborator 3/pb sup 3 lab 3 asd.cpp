//Laborator 3 ASD ---- Staniea Alexandru -- Grupa 132

//Probleme suplimentare
//Problema 3

#include <iostream>
#include<math.h>
using namespace std;

struct pol {
             int gr, coef;
             pol *next;
            };

pol *start;

void adaugare_grad(pol *p)
{
    int m,n;

    cout<<"Adaugati coeficientul: "<<endl;
    cin>>n;
    cout<<"Adaugati gradul: "<<endl;
    cin>>m;

    p=start;
    pol *f=new pol;
    f->coef=n;
    f->gr=m;
    f->next=NULL;

    if(p==NULL)   //polinom gol
       {
        p=f;
       }
    else{
          while(p->next!=NULL)
      {
         p=p->next;
      }

         p->next=f;
        }
}


void afisare_rezultat(int val,pol *p)
 {
     int rezultat=0;
     p=start;
     while(p!=NULL)
     {
          rezultat+=(p->coef*(pow(val,p->gr)));
          p=p->next;

     }
     cout<<rezultat<<endl;
 }

int main()
{
    start = new pol;
    pol *r = new pol;

    int m,n,nrgr,val;

    cout<<"Cati termeni avand coeficient nenul are polinomul?"<<endl;
    cin>>nrgr;

    cout<<"Adaugati coeficientul: "<<endl;
    cin>>n;
    cout<<"Adaugati gradul: "<<endl;
    cin>>m;

    start->coef=n;
    start->gr=m;
    start->next=NULL;

    for(int i=1;i<nrgr;i++)  //< pt ca primul grad e scris in start
         adaugare_grad(r);

    cout<<"Numarul in care doriti valoarea polinomului"<<endl;
    cin>>val;

    cout<<"Valoarea este: ";
    afisare_rezultat(val,r);
}

