//Laborator 3 ASD ---- Staniea Alexandru -- Grupa 132

//Probleme suplimentare
//Problema 2

#include <iostream>
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

void inmultire(int a,pol *p)
{
    p=start;
    while(p!=NULL)
    {
        p->coef*=a;
        p=p->next;
    }
}

void afisare(pol *p)
 {

     p=start;
     while(p!=NULL)
     {
         if(p->coef>0)
         cout<<" +"<<p->coef<<"*X^"<<p->gr;
         else
         cout<<" "<<p->coef<<"*X^"<<p->gr;
         p=p->next;
     }
 }

int main()
{
    start = new pol;
    pol *r = new pol;

    int m,n,nrgr,a;

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


    cout<<"Cu ce scalar vreti sa il inmultiti?"<<endl;
    cin>>a;

    inmultire(a,r);
    cout<<"Polinomul obtinut este: ";
    afisare(r);
}

