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

int findMin(nod *p)
{
    if(p==NULL)
        return 0;
    else
    {
        while(p->left!=NULL)
            p=p->left;
    }
    return p->info;
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

nod* sterge(nod *root,int val)
{
    if(root==NULL) return root;
    else if(root->info>val)
        root->left=sterge(root->left,val);
    else if(root->info<val)
        root->right=sterge(root->right,val);
    else
    {
        if(root->right==NULL && root->left==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            nod* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL)
        {
            nod* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else
        {
            nod *temp;
            temp->info=findMax(root->left);
            root->info=temp->info;
            root->left=sterge(root->left,temp->info);
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


int main()
{
    int i,n,k,z,g;
    nod *p;
    root= new nod;
    root=NULL;

    cout<<"Cate numere avem?"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>k;
        adaugare_nod(k,root);
    }


    for(i=0;i<n;i++)
    {
        cout<<findMin(root)<<' ';
        root=sterge(root,findMin(root));

    }



}
