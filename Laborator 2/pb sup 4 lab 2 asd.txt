//Laborator 2 ASD ---- Staniea Alexandru -- Grupa 132

//Probleme suplimentare
//Problema 4

#include <iostream>
using namespace std;

struct nod {
             int info;
             nod *next;
            };

nod *start1;   //primul element din lista care retine primul nr
nod *start2;   //primul element din lista care retine al doilea nr
nod *start3;   //primul element din lista care retine suma nr

void push_in_lista1(int nr)
{
    nod *p= new nod;
    p->info=nr;
    p->next=start1;
    start1=p;
}

void push_in_lista2(int nr)
{
    nod *p= new nod;
    p->info=nr;
    p->next=start2;
    start2=p;
}

void push_in_suma(int nr)
{
    nod *p= new nod;
    p->info=nr;
    p->next=start3;
    start3=p;
}

void suma(nod *p,nod *q)
{
    p=start1;
    q=start2;
    int c=0;         //c adauga 1 pe poz urmatoare in caz ca suma elem e peste 9

    while(p!=NULL&&q!=NULL)
    {
         if(p->info+q->info>9)
        {
            push_in_suma(((p->info+q->info)+c)%10);
            c=1;
        }
         else
            {
                push_in_suma(((p->info+q->info)+c)%10);
                if((p->info+q->info)+c>9)                //cazul in care mai multe cifre alaturate dau peste 10
                {
                    c=1;
                }
                else
                    c=0;
            }
        p=p->next;
        q=q->next;
    }

    if(p==NULL&&q==NULL&&c==1)   //cazul 999+999 -->din care rezulta a 4-a cifra
         push_in_suma(1);


    if(p!=NULL)
     {
        while(p!=NULL)
          {
            push_in_suma((p->info+c)%10);
            if(p->info+c>9)
                c=1;                       //cazul 1+9999
            else c=0;
            p=p->next;
          }
          if(p==NULL&&c==1)
            push_in_suma(1);
     }

     if(q!=NULL)
     {
        while(q!=NULL)
          {
            push_in_suma((q->info+c)%10);
            if(q->info+c>9)
                c=1;                        //cazul 9999+1
            else c=0;
            q=q->next;
          }
          if(q==NULL&&c==1)
            push_in_suma(1);
     }


}

void afisare(nod *p)
 {
     p=start3;
     cout<<"Suma este: ";
     while(p!=NULL)
     {
         cout<<p->info;
         p=p->next;
     }
 }

int main()
{

    start1 = new nod;
    start2 = new nod;
    start3 = new nod;
    nod *p=new nod;
    nod *q=new nod;

    start1=NULL;
    start2=NULL;
    start3=NULL;

    int n,m,i,j,k;
    cin>>n>>m;
    for(i=0;i<n;i++)
        {cin>>k;
        push_in_lista1(k);}

    for(j=0;j<m;j++)
    {
        cin>>k;
        push_in_lista2(k);


    }


    suma(p,q);
    afisare(p);
}










