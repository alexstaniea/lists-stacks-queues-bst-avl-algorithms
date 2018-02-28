#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
            };

nod *top;

void push(int val)
{
    nod *f= new nod;
    f->info=val;
    f->next=top;
    top=f;
}

int pop()
{
  if(top!=NULL)
  {
   nod *temp=top;
   top=top->next;
   return temp->info;
   delete temp;
   }

}

int peek()
{
    if(top!=NULL)
    return top->info;
}

bool isempty(nod *p)
{
    p=top;
    if(top==NULL)
        return true;
    else return false;
}

int cauta(int val, nod *p)
{
    int distanta=0;
    p=top;
    while(p!=NULL && p->info!=val)
        {p=p->next;
         distanta++;}
    if(p==NULL)
        return -1;
    else return distanta;
}

void afisare(nod *p)
 {

     p=top;
     while(p!=NULL)
     {
         cout<<p->info<<' ';
         p=p->next;
     }
     cout<<endl;
 }


int main()
{
    top =new nod;
    nod *p;
    top=NULL;
    int n,i,k,x,z;

    cout<<"Cate elemente doriti sa aiba stiva?"<<endl;
    cin>>n;
    if(n!=0)
    {
    cout<<"Introduceti elementele:"<<endl;

    for(i=0;i<n;i++)
    {
        cin>>k;
        push(k);
    }
    }

    if(n==0) {cout<<"empty(): 1"<<endl;}
    else{
    cout<<"Stiva este: ";
    afisare(p);
    cout<<"Pop(): ";
    cout<<pop()<<endl;
    cout<<"Stiva este: ";
    afisare(p);
    cout<<"Peek(): ";
    cout<<peek()<<endl;
    cout<<"Stiva este: ";
    afisare(p);
    cout<<"empty(): ";
    cout<<isempty(p)<<endl;
    cout<<"Stiva este: ";
    afisare(p);}
    cout<<"Introduceti valoarea pe care doriti sa o cautati:"<<endl;
    cin>>z;
    cout<<"Distanta este: ";
    cout<<cauta(z,p)<<endl;



}


