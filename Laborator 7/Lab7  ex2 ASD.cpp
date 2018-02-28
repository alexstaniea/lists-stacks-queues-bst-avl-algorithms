#include<iostream>
#include<queue>
using namespace std;

struct nod{
int info;
nod *left,*right;
};

nod *root;

void adaugare_nod(int val, nod *p)
{
    nod *oldp;
    nod *f=new nod;
    f->info=val;
    f->left=NULL;
    f->right=NULL;

    if(root==NULL)
    {
        root=f;
    }
    else
    {
        oldp=p;
        while(p!=NULL)
        {
          if(p->info==val)
          {
             cout<<"Nu putem adauga dubluri"<<endl;
             break;
          }
          else if(p->info>val)
          {
              oldp=p;
              p=p->left;
          }
          else if(p->info<val)
          {
              oldp=p;
              p=p->right;
          }
        }
        if(oldp->info<val)
            oldp->right=f;
        else if(oldp->info>val)
            oldp->left=f;
    }
}

int cautare(nod *p,int val)
{
    if(root==NULL)
       return 0;
    else
    {
        while(p)
        {
            if(p->info==val)
                return 1;
            else if(p->info>val)
                p=p->left;
            else if(p->info<val)
                p=p->right;
        }
        return 0;
    }
}

int findMax(nod *p)
{
    if(p==NULL)
        return 0;
    else
    {
        while(p->right!=NULL)
            p=p->right;
    }
    return p->info;
}

nod* findmin(nod *p)
{
    nod* current = p;
    while (current->left != NULL)
        current = current->left;

    return current;
}

nod* sterge(nod *root,int val)
{
    if(root==NULL) return root;

    if(val<root->info)
        root->left=sterge(root->left,val);
    else if(val>root->info)
        root->right=sterge(root->right,val);
    else
    {
        if(root->left==NULL)
        {
            nod* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            nod* temp=root->left;
            delete root;
            return temp;
        }


            nod *temp = findmin(root->right);
            root->info=temp->info;
            root->right = sterge(root->right,temp->info);

    }
    return root;

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


int main()
{
    int i,n,k,z,g;
    nod *p;
    root= new nod;
    root=NULL;

    cout<<"Cate noduri are arborele binar de cautare?"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Introduceti cheia nodului: ";
        cin>>k;
        adaugare_nod(k,root);
    }
    cout<<endl;
    cout<<"Afisare in latime: ";
    afisare();
    cout<<endl<<endl;
    if(findMax(root)!=0)
    {
        cout<<"Maximul din arbore este: ";
        cout<<findMax(root);
        cout<<endl<<endl;
    }
    else
        cout<<"Nu exista maxim!"<<endl;
    cout<<"Cheia elementului de cautat: ";
    cin>>z;
    if(cautare(root,z))
        cout<<"Elementul se afla in arbore!"<<endl;
    else
        cout<<"Elementul NU se afla in arbore!"<<endl;
    cout<<endl;

    cout<<"Inserati cheia elementului pe care doriti sa il stergeti: ";
    cin>>g;
    root=sterge(root,g);
    cout<<endl;

    cout<<"Arborele afisat in latime este: ";
    afisare();
    cout<<endl;


}
