#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *next;
            };

nod *start;
nod *rear;


void push(int val)
{
    nod *f= new nod;
    f->info=val;
    f->next=NULL;
    if(start==NULL)
    {start=f;
     rear=f;}
    else
    {rear->next=f;
    rear=f;}
}

int pop()
{
  if(start!=NULL && rear!=NULL)
  {
   nod *temp=start;
   start=start->next;
   return temp->info;
   delete temp;
   }
   if(start==rear)
    {delete start;
     start=rear=NULL;}
}

int peek()
{
    if(start!=NULL)
    return start->info;
}

bool isempty(nod *p)
{
    if(start==NULL && rear==NULL)
        return true;
    else return false;
}

int cauta(int val, nod *p)
{
    int distanta=0;
    p=start;
    if(p!=NULL){
    while(p!=rear->next && p->info!=val)
        {p=p->next;
         distanta++;}
    if(p==rear->next)
        return -1;
    else return distanta;}
    else return -1;
}

void afisare(nod *p)
 {

     p=start;
     if(p!=NULL){
     while(p!=rear->next)
     {
         cout<<p->info<<' ';
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

    int n,i,k,x,z;

    cout<<"Cate elemente doriti sa aiba coada?"<<endl;
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
    cout<<"Coada este: ";
    afisare(p);
    cout<<"Pop(): ";
    cout<<pop()<<endl;
    cout<<"Coada este: ";
    afisare(p);
    cout<<"Peek(): ";
    cout<<peek()<<endl;
    cout<<"Coada este: ";
    afisare(p);
    cout<<"empty(): ";
    if(n==1)cout<<"1"<<endl;
    cout<<isempty(p)<<endl;
    cout<<"Coada este: ";
    afisare(p);}
    cout<<"Introduceti valoarea pe care doriti sa o cautati:"<<endl;
    cin>>z;
    cout<<"Distanta este: ";
    cout<<cauta(z,p)<<endl;

}


