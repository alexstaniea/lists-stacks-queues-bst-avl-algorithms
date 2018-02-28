#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
            };

nod *start1;   //start pt lista c
nod *start2;   //start pt lista a
nod *start3;   //start pt lista b


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

void despartire_lista(nod *p)
{
     p=start1;
     nod *a,*olda,*b,*oldb;

     if(p!=NULL){
     while(p!=NULL)
     {
         a=p;
         p=p->next;

         if(start2==NULL)
            start2=a;
         else olda->next=a;

         olda=a;

         if(p==NULL)
          break;

         b=p;
         p=p->next;

        if(start3==NULL)
            start3=b;
         else oldb->next=b;

         oldb=b;
     }
     if(start1->next!=NULL){
     olda->next=NULL;
     oldb->next=NULL;}}

     else cout<<"Lista vida!"<<endl;
}


void afisareA(nod *p)
 {
    p=start2;
     while(p!=NULL)
     {
         cout<<p->info<<' ';
         p=p->next;
     }
 }


void afisareB(nod *p)
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
   nod *r;
   start1=NULL;
   start2=NULL;
   start3=NULL;

   int i,n,k;

    cout<<"Cate elemente are lista C?"<<endl;
    cin>>n;

    if(n>0){
    cout<<"Introduceti elementele:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>k;
        adaugare_nod1(k,r);
    }

    despartire_lista(r);

    cout<<"Elementele listei A sunt:"<<endl;
    afisareA(r);
    cout<<endl;
    cout<<"Elementele listei B sunt:"<<endl;
    afisareB(r);
    cout<<endl;}

    else despartire_lista(r);
}


