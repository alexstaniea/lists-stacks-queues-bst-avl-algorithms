#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
            };

nod *start1;
nod *start2;
nod *start3;


void adaugare_nod1(int val,nod *p)
{
    nod *f= new nod;
    f->info=val;
    f->next=NULL;
    if(start1==NULL)
       start1=f;
    else
    {p=start1;
      while(p->next!=NULL)
        p=p->next;
      p->next=f;
    }
}

void adaugare_nod2(int val,nod *p)
{
    nod *f= new nod;
    f->info=val;
    f->next=NULL;
    if(start2==NULL)
       start2=f;
    else
    {p=start2;
      while(p->next!=NULL)
        p=p->next;
      p->next=f;
    }
}


void interclas(nod *p,nod*q)
{
      p=start1;
      q=start2;
      nod *a;
      nod *olda;


      while(p!=NULL&&q!=NULL)
      {
        if(p->info>q->info)
           {
                a=q;
                q=q->next;
           }
        else if(q->info>p->info)
           {
                a=p;
                p=p->next;
           }
        else
           {
                a=p;
                p=p->next;

           }
        if(start3==NULL)
            start3=a;
        else
            olda->next=a;

        olda=a;
      }
    while(p!=NULL)
           {
                a=p;
                if(start3==NULL)
                    start3=a;
                else olda->next=a;
                olda=a;
                p=p->next;
           }
    while(q!=NULL)
           {
                a=q;
                if(start3==NULL)
                    start3=a;
                else olda->next=a;
                olda=a;
                q=q->next;
           }
}


void afisare(nod *p)
 {

     p=start3;
     while(p!=NULL)
     {
         cout<<p->info<<' ';
         p=p->next;
     }
 }


 int main()
{
   start1 = new nod;
   start2 = new nod;

   nod *r;
   nod *q;
   start1=NULL;
   start2=NULL;
   start3=NULL;


   int n,i,k,m;

    cout<<"Cate elemente are lista A?"<<endl;
    cin>>n;

    cout<<"Introduceti elementele in ordine crescatoare:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>k;
        adaugare_nod1(k,r);
    }

    cout<<"Cate elemente are lista B?"<<endl;
    cin>>m;

    cout<<"Introduceti elementele in ordine crescatoare:"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>k;
        adaugare_nod2(k,r);
    }


    interclas(r,q);



    cout<<"Elementele listei C sunt:"<<endl;
    afisare(r);

}










