//Laborator 3 ASD --- Staniea Alexandru -- Grupa 132

//Problema obligatorie

#include <iostream>

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
    {p=start;
      while(p->next!=NULL)
        p=p->next;
      p->next=f;
    }

}


void t3ex1(int valz,nod *p)
{
    p=start;

    nod *oldp,*z;     //z e nodul adaugat
    oldp = new nod;    //valz e valoarea nodului adaugat
    z = new nod;        //oldp e nodul din spatele lui p
    z->info=valz;        //de care avem nevoie pentru a face legatura

    while((p!=NULL)&&(p->info<valz))
        {
            oldp=p;
            p=p->next;
        }

    if(p!=NULL)
    {
      oldp->next=z;
      z->next=p;
    }
    else
    {
        oldp->next=z;
        z->next=NULL;
    }

    if(p==start)   //cazul in care nodul trebuie adaugat inainte de primul nod
        start=z;

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

    nod *r=new nod;
    start= new nod;
    start=NULL;

    int n,k,i,o;

    cout<<"Cate elemente are lista?"<<endl;
    cin>>n;

    cout<<"Introduceti elementele:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>k;
        t3ex1(k,r);
    }
    cout<<"Lista ordonata este:"<<endl;

    afisare(r);
 }
