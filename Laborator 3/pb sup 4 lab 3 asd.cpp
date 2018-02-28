 //Laborator 3 ASD ---- Staniea Alexandru -- Grupa 132

//Probleme suplimentare
//Problema 4

#include <iostream>
using namespace std;

struct pol {
             int gr, coef;
             pol *next;
            };

pol *start1;
pol *start2;
pol *start3;


void adaugare_grad1(pol *p)
{
    int m,n;

    cout<<"Adaugati coeficientul: "<<endl;
    cin>>n;
    cout<<"Adaugati gradul: "<<endl;
    cin>>m;

    p=start1;
    pol *f=new pol;
    f->coef=n;
    f->gr=m;
    f->next=NULL;

    if(start1==NULL)   //polinom gol
       {
        start1=f;
       }
    else{
          while(p->next!=NULL)
      {
         p=p->next;
      }

         p->next=f;
        }
}

void adaugare_grad2(pol *p)
{
    int m,n;

    cout<<"Adaugati coeficientul: "<<endl;
    cin>>n;
    cout<<"Adaugati gradul: "<<endl;
    cin>>m;

    p=start2;
    pol *f=new pol;
    f->coef=n;
    f->gr=m;
    f->next=NULL;

    if(start2==NULL)   //polinom gol
       {
        start2=f;
       }
    else{
          while(p->next!=NULL)
      {
         p=p->next;
      }

         p->next=f;
        }
}

void adaugare_grad_suma(int coef,int gr, pol *p)
{
    p=start3;
    pol *f=new pol;
    f->coef=coef;
    f->gr=gr;
    f->next=NULL;

    if(start3==NULL)   //polinom gol
       {
        start3=f;
       }
    else{
          while(p->next!=NULL)
         {
           p=p->next;
         }

         p->next=f;
        }
}

void suma(pol *p,pol *q)
{
    p=start1;
    q=start2;
    pol *f=new pol;

   while(p!=NULL&&q!=NULL)
   {
     if(p->gr!=q->gr)
       {
        if(p->gr>q->gr)
        {
         adaugare_grad_suma(p->coef,p->gr,f);
         p=p->next;
        }
         else
         {
           adaugare_grad_suma(q->coef,q->gr,f);
           q=q->next;
         }
        }
     else
     {
      adaugare_grad_suma(q->coef+p->coef,q->gr,f);
      q=q->next;
      p=p->next;
     }
    }

    while(p!=NULL)
    {adaugare_grad_suma(p->coef,p->gr,f);
         p=p->next;}

         while(q!=NULL)
    {adaugare_grad_suma(q->coef,q->gr,f);
         q=q->next;}




}



void afisare(pol *p)
 {

     p=start3;
     while(p!=NULL)
     {
         if(p->coef>=0)
         cout<<" +"<<p->coef<<"*X^"<<p->gr;
         else
         cout<<" -"<<p->coef<<"*X^"<<p->gr;
         p=p->next;
     }
 }

int main()
{
    start1 = new pol;
    start2 = new pol;
    start3 = new pol;
    pol *r = new pol;
    pol *q = new pol;
    pol *p = new pol;
    start1=NULL;
    start2=NULL;
    start3=NULL;

    int m,n,nrgr1,nrgr2,i;

    cout<<"Cati termeni avand coeficient nenul are polinomul 1?"<<endl;
    cin>>nrgr1;
    cout<<"Cati termeni avand coeficient nenul are polinomul 2?"<<endl;
    cin>>nrgr2;


    for(i=1;i<=nrgr1;i++)
         adaugare_grad1(r);

    for(i=1;i<=nrgr2;i++)
        adaugare_grad2(r);

    suma(p,q);

    cout<<"Suma polinoamelor este: ";
    afisare(r);
}

