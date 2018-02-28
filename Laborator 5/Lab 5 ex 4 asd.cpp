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

void pop()
{
  if(top!=NULL)
  {
   nod *temp=top;
   top=top->next;
   delete temp;
   }

}

bool isempty(nod *p)
{
    p=top;
    if(top==NULL)
        return true;
    else return false;
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
    int n,i,pereche[50];

    cout<<"Cati pini sunt?"<<endl;
    cin>>n;

    if(n>0){
    cout<<"Introduceti elementele vectorului pereche:"<<endl;

    for(i=0;i<n;i++)
    {
        cin>>pereche[i];
        if(top!=NULL && pereche[i]==top->info)
        {
            pop();
        }
        else{
            push(pereche[i]);
        }
    }



    if(isempty(p))
        cout<<"Pinii pereche pot fi conectati."<<endl;
    else
    cout<<"Pinii pereche NU pot fi conectati."<<endl;}
    else cout<<"Variabila n trebuie sa fie pozitiva nenula!"<<endl;

}





