//Laborator 2 ASD ---- Staniea Alexandru -- Grupa 132


//Probleme suplimentare:
//problema 2

/*
 #include <iostream>

using namespace std;


 struct nod{
           int info;
           nod *next;
            };
nod *start;



 void program(nod *p,int &nrpare,float &medimpare)
 {

     int nrimpare=0;
     float sumaimpare=0;


     p=start;

     while(p!=NULL)
     {
         if((p->info)%2==0)
              nrpare++;
         else
            {
              nrimpare++;
              sumaimpare+=p->info;
            }
         p=p->next;
     }

     medimpare=(sumaimpare/nrimpare);
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
     nod *r,*q,*n,*o,*t;
     t = new nod;
     start = new nod;
     r= new nod;
     q= new nod;
     n= new nod;
     o=new nod;

     int nrpare=0;
     float medimpare;

     start->info=7;
     start->next=q;
     q->info=3;
     q->next=n;
     n->info=9;
     n->next=o;
     o->info=1;
     o->next=NULL;

     afisare(r);
     program(r,nrpare,medimpare);
     cout<<"In lista sunt "<<nrpare<<" numere pare, iar media aritmetica a numerele impare este "<<medimpare<<'.'<<endl;



 }



*/





/*

//problema 3

#include <iostream>

using namespace std;


 struct nod{
           float info;
           nod *next;
            };
nod *start;

void adaugare_inainte_de_o_val(int val,nod *p)
{
    p=start;

    nod *oldp,*z;     //z e nodul adaugat
    oldp = new nod;
    z = new nod;        //val e valoarea inaintea careia adaugam nodul


    while((p->info!=val)&&(p!=NULL))
        {
          oldp=p;
          p=p->next;
        }

    if(p!=NULL)
     {
         float c=(oldp->info)+(p->info);

         z->info=float(c/2.0);
         oldp->next=z;
         z->next=p;
     }
    else
        cout<<"Valoarea introdusa nu este in stiva!";


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
     nod *r,*q,*n,*o,*t;
     t = new nod;
     start = new nod;
     r= new nod;
     q= new nod;
     n= new nod;
     o=new nod;

     int val,i;

     start->info=1;
     start->next=q;
     q->info=2;
     q->next=n;
     n->info=3;
     n->next=o;
     o->info=4;
     o->next=NULL;

     for(i=2;i<5;i++)
     adaugare_inainte_de_o_val(i,r);
     afisare(r);



 }
*/
