//pb 1 subpct 1
#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
            };

nod *start1;
nod *start2;

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

void adaugare_nod2(int nr)
{
    nod *p= new nod;
    p->info=nr;
    p->next=start2;
    start2=p;
}


void afisare(nod *p)
 {

     p=start2;
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
   nod *r=new nod;
   start1=NULL;
   start2=NULL;

   int n,i,k;

    cout<<"Cate elemente are lista?"<<endl;
    cin>>n;

    cout<<"Introduceti elementele:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>k;
        adaugare_nod1(k,r);
        adaugare_nod2(k);
    }
    cout<<"Lista inversata este:"<<endl;
    afisare(r);


}
