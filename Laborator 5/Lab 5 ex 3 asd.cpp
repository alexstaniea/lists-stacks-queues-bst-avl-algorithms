#include<iostream>
#include<string.h>
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
    int n,i=0;
    char c;

    cout<<"Cate caractere are sirul?"<<endl;
    cin>>n;
    cout<<"Introduceti caracterele:"<<endl;

    while(i<n)
    {
        if(isempty(p))
        {
            cin>>c;
            i++;
            if(c==')')
                break;
            else if(c=='(')
                push(1);
        }
        else{
        cin>>c;
        i++;
        if(c=='(')
            push(1);
        else if (c==')')
            pop();
        }
    }

    if(i==n && isempty(p))
        cout<<"Sirul este corect parantezat."<<endl;
    else
    {cout<<"Sirul NU este corect parantezat."<<endl;
     cout<<"Pozitia primei paranteze ) fara corespondent este:";
     cout<<" "<<i<<'.'<<endl;
    }

}





