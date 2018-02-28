#include<iostream>
using namespace std;

struct nod{
           int info;
           int prioritate;
           nod *next;
            };

nod *start;
nod *rear;


void push(int val,int pr)
{
    nod *f= new nod;
    f->info=val;
    f->prioritate=pr;
    f->next=NULL;

    if(start==NULL)
    {start=f;
     rear=f;}
    else
    {
        if(pr<start->prioritate)
        {
            f->next=start;
            start=f;
        }
        else
        {
        nod *p,*oldp;
        p=start;
        while(p!=rear->next && p->prioritate<=pr)
            {oldp=p;
             p=p->next;}

        if(p==rear->next)
        {
            rear->next=f;
            rear=f;
        }
        else
        {
            oldp->next=f;
            f->next=p;
        }
        }
    }
}

int pop()
{
  if(start!=NULL && rear!=NULL)
  {
      start=start->next;
  }
  if(start==rear)
  {
      start=rear=NULL;
  }
}

void afisare(nod *p)
 {

     p=start;
     if(p!=NULL){
     while(p!=rear->next)
     {
         cout<<"Valoare nod: "<<p->info<<','<<"Prioritate nod: "<<p->prioritate<<endl;
         p=p->next;
     }
     cout<<endl;}
     else cout<<endl;
 }

 int main()
{
    start =NULL;
    rear=NULL;
    nod *p;

    int n,k,m,pr,i;

    cout<<"Cate elemente doriti sa aiba coada cu prioritati?"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Introduceti valoarea nodului:"<<endl;
        cin>>k;
        cout<<"Introduceti prioritatea nodului:"<<endl;
        cin>>m;
        push(k,m);
    }

    afisare(p);
}
