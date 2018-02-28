//b)
#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
          };
nod *start;

void adaugare_nod(int val,nod *p)
{
    nod *f= new nod;
    f->info=val;
    f->next=NULL;
    if(start==NULL)
       start=f;
    else
    {
      p=start;
      while(p->next!=NULL)
      p=p->next;
      p->next=f;
    }
}

void schimbare_elemente(nod *p)
{
    p=start->next;
    start->next=NULL;
    while(p!=NULL)
    {
      nod *temp=p->next;
      p->next=start;
      start=p;
      p=temp;
    }
}


void afisare(nod *p)
 {
     p=start;
     while(p!=NULL)
     {
         cout<<p->info<<' ';
         p=p->next;
     }
 }

int main()
{
    start= new nod;
    nod *r=new nod;
    start=NULL;
    int n,i,k;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>k;
        adaugare_nod(k,r);
    }
    schimbare_elemente(r);
    afisare(r);
}
