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
            if(c=='a')
            {
              push(1);
              i++;
              while(!isempty(p) && i<n)
              {
                cin>>c;
                if(c=='a')
                  push(1);
                else if(c=='b')
                  pop();
                else {cout<<"Caracter invalid!"<<endl;i--; }
                i++;
              }
            }

            else if(c=='b')
            {
               push(1);
               i++;
               while(!isempty(p) && i<n)
               {
                cin>>c;
                if(c=='b')
                  push(1);
                else if(c=='a')
                 pop();
                 else {cout<<"Caracter invalid!"<<endl;i--; }
                i++;
               }
            }
            else cout<<"Caracter invalid!"<<endl;
        }
    }



    if(isempty(p))
        cout<<"Numarul de caractere 'a' este acelasi cu numarul de caractere 'b'."<<endl;
    else
    cout<<"Numarul de caractere 'a' NU este acelasi cu numarul de caractere 'b'."<<endl;

}





