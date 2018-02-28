#include<iostream>
using namespace std;

struct nod{
           int info;
           nod *last;
           nod *next;
            };

nod *start;

void adaugare_inceput(int val)
{

    nod *p=new nod;
    p->info=val;
    p->last=NULL;

    if(start!=NULL)
    {
        p->next=start;
        start=p;
    }
    else
    {
        p->next=NULL;
        start=p;
    }
}

void adaugare_sfarsit(int val)
{
    nod *p=new nod;
    p->info=val;
    p->next=NULL;

    if(start!=NULL)
    {
    nod *r;
    r=start;

    while(r->next!=NULL)
        r=r->next;

    r->next=p;
    p->last=r;
    }
    else
    {
    p->last=NULL;
    start=p;
    }
}

void adaugare_dupa_start(int val)
{
    nod *p=new nod;
    p->info=val;

    if(start==NULL)
    {
     start=p;
     start->next=NULL;
     start->last=NULL;
    }
    else if(start->next==NULL)
    {
        start->next=p;
        p->next=NULL;
        p->last=start;
    }
    else if(start!=NULL){
    p->last=start;
    p->next=start->next;
    start->next->last=p;
    start->next=p;}

}


void stergere_dupa_val(int val)
{
    if(start->info==val)
    {
        start=start->next;
    }
    else
    {
    nod *p,*oldp;
    p=start;

    while(p!=NULL && p->info!=val)
        {
        oldp=p;
         p=p->next;
        }


    if(p==NULL)
        cout<<"Valoarea nu este in lista!"<<endl;
    else if(p->next==NULL)
    {
        oldp->next=NULL;
    }
    else if(p!=NULL)
    {
        oldp->next=p->next;
        p->next->last=oldp;
    }
    }
}

void stergere_dupa_nrord(int nrord)
{

    int z=1;
    nod *p,*oldp;
    p=start;

    if(nrord==1)
        start=start->next;
    else
    {
    while(p!=NULL && z<nrord)
    {
        oldp=p;
        p=p->next;
        z++;
    }
    if(p==NULL)
        cout<<"Valoarea nu este in lista!"<<endl;
    else if(p->next==NULL)
    {
        oldp->next=NULL;
    }
    else if(p!=NULL)
    {
        oldp->next=p->next;
        p->next->last=oldp;
    }
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

 void afisare_inversa(nod *p)
 {
     p=start;
     while(p->next!=NULL)
        p=p->next;

     while(p!=NULL)
     {
         cout<<p->info<<' ';
         p=p->last;
     }
     cout<<endl;
 }

int main()
{
    start= new nod;
    start= NULL;
    nod *r;
    int n,i,p=0;

    cout<<"1) Adaugarea unui element la inceput;"<<endl;
    cout<<"2) Adaugarea unui element la sfarsit;"<<endl;
    cout<<"3) Adaugarea unui element in interiorul listei;"<<endl;
    cout<<"4) Afisarea elementelor listei in ordinea introducerii lor;"<<endl;
    cout<<"5) Afisarea elementelor listei in ordine inversa;"<<endl;
    cout<<"6) Stergerea unui element din lista stiind numarul lui de ordine;"<<endl;
    cout<<"7) Stergerea unui element din lista stiind valoarea lui."<<endl;
    cout<<"Selectati optiunea dorita:"<<endl;


   while(p==0)
    {
        cin>>n;
        switch(n)
       {

        case 1:{
            cout<<"Introduceti valoarea elementului:"<<endl;
            cin>>i;
            adaugare_inceput(i);
            break;}
        case 2:{
            cout<<"Introduceti valoarea elementului:"<<endl;
            cin>>i;
            adaugare_sfarsit(i);
            break;}
        case 3:{
            cout<<"Introduceti valoarea elementului:"<<endl;
            cin>>i;
            adaugare_dupa_start(i);
            break;}
        case 4:{
            cout<<"Elementele listei sunt:"<<endl;
            afisare(r);
            break;}
        case 5:{
            cout<<"Elementele listei inversate sunt:"<<endl;
            afisare_inversa(r);
            break;}
        case 6:{
            cout<<"Introduceti numarul de ordine al elementului de sters:"<<endl;
            cin>>i;
            stergere_dupa_nrord(i);
            break;}
        case 7:{
            cout<<"Introduceti valoarea elementului de sters:"<<endl;
            cin>>i;
            stergere_dupa_val(i);
            break;}
       }
    cout<<"Doriti sa iesiti din program?(0/1)"<<endl;
    cin>>p;
    }

}
