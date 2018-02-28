#include<iostream>
#include<string.h>
using namespace std;

struct nod{
           int info;
           nod *next;
           nod *last;
            };

nod *start;

void push_inceput(int val)
{
    nod *f= new nod;
    f->info=val;
    f->last=NULL;

    if(start!=NULL)
    {
    f->next=start;
    start=f;
    }
    else
    {
        start=f;
        start->next=NULL;
    }
}

void push_sfarsit(int val)
{
    nod *f= new nod;
    f->info=val;
    f->next=NULL;

    if(start!=NULL)
    {
      nod *p=start;
       while(p->next!=NULL)
           p=p->next;
      p->next=f;
      f->last=p;
    }
    else
    {
      start=f;
      start->next=NULL;
      start->last=NULL;
    }
}

void pop_inceput()
{
  if(start!=NULL)
  {
    start->next->last=NULL;
    start=start->next;

  }
}

void pop_sfarsit()
{
  if(start!=NULL)
  {
  nod *p=start;
  while(p->next->next!=NULL)
    p=p->next;
  p->next=NULL;
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
     cout<<endl;
 }

 int main()
{
    start =new nod;
    nod *p;
    start=NULL;
    int n,k,z=0;

    cout<<"1)Adauga la sfarsitul listei."<<endl;
    cout<<"2)Adauga la inceputul listei."<<endl;
    cout<<"3)Sterge elementul de la sfarsitul listei."<<endl;
    cout<<"4)Sterge elementul de la inceputul listei."<<endl;
    cout<<"5)Afiseaza elementele listei."<<endl;



while(z==0)
{
    cin>>n;
    switch(n){
        case 1:
            cout<<"Introduceti elementul de adaugat:"<<endl;
            cin>>k;push_sfarsit(k);break;
        case 2:
            cout<<"Introduceti elementul de adaugat:"<<endl;
            cin>>k;push_inceput(k);
            break;
        case 3:
            pop_sfarsit();
            break;
        case 4:
            pop_inceput();
            break;
        case 5:
            cout<<"Elementele listei sunt:"<<endl;
            afisare(p);
            break;
    }
    cout<<"Iesiti din program?(0/1)"<<endl;
    cin>>z;
}

}


