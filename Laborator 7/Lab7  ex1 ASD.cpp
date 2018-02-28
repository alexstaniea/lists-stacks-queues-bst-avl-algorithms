#include<iostream>
#include<queue>
using namespace std;

struct nod{
int info;
nod *left,*right;
};

nod *root;

adaugare_nod(int val)
{
    nod *f= new nod;
    f->info=val;
    f->left=NULL;
    f->right=NULL;
    if(root==NULL)
    {
        root=f;
    }
    else
    {
         queue <nod*> q;
         q.push(root);
         while(!q.empty())
         {
             nod *temp=q.front();

             if (temp->left==NULL)
                {
                  temp->left=f;
                  break;
                }
             else
             q.push(temp->left);

             if (temp->right==NULL)
                {
                  temp->right=f;
                  break;
                }
             else
             q.push(temp->right);

             q.pop();
         }
    }
}

void afisare()
{
    if(root==NULL) return;
    queue<nod*> q;
    q.push(root);
    while(!q.empty())
    {
        nod *temp=q.front();
        cout<<temp->info<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        q.pop();
    }
}

void afisare_rsd(nod *p)
{
    if(p!=NULL)
    {
        cout<<p->info<<" ";
        afisare_rsd(p->left);
        afisare_rsd(p->right);
    }
}

void afisare_srd(nod *p)
{
    if(p!=NULL)
    {
        afisare_srd(p->left);
        cout<<p->info<<" ";
        afisare_srd(p->right);
    }
}

void afisare_sdr(nod *p)
{
    if(p!=NULL)
    {
        afisare_sdr(p->left);
        afisare_sdr(p->right);
        cout<<p->info<<" ";
    }
}


int main()
{
    int i,n,k;
    nod *p;
    root= new nod;
    root=NULL;

    cout<<"Cate noduri are arborele?"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Introduceti cheia nodului: ";
        cin>>k;
        adaugare_nod(k);

    }
    cout<<endl;
    cout<<"Afisare in latime: ";
    afisare();
    cout<<endl;
    cout<<"Afisare RSD: ";
    afisare_rsd(root);
    cout<<endl;
    cout<<"Afisare SRD: ";
    afisare_srd(root);
    cout<<endl;
    cout<<"Afisare SDR: ";
    afisare_sdr(root);
    cout<<endl;
}
