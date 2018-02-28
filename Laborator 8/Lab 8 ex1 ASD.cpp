#include<iostream>
#include<queue>
using namespace std;

struct nod{
int info;
nod *left,*right;
int h;
};

nod *root;

nod* nod_nou(int val)
{
    nod * nodn = new nod;
    nodn->info=val;
    nodn->left=NULL;
    nodn->right=NULL;
    nodn->h=1;

    return(nodn);
}


int max(int a, int b)
{
    return (a > b)? a : b;
}

int inaltime(nod *p)
{
    if (p == NULL)
        return 0;
    return p->h;
}

nod* Rotatie_Dreapta(nod *p)
{
    nod *x = p->left;
    nod *T2 = x->right;

    x->right = p;
    p->left = T2;

    p->h = max(inaltime(p->left), inaltime(p->right))+1;
    x->h = max(inaltime(x->left), inaltime(x->right))+1;

    return x;
}

nod* Rotatie_Stanga(nod *p)
{
    nod *y = p->right;
    nod *T2 = y->left;

    y->left = p;
    p->right = T2;

    p->h = max(inaltime(p->left), inaltime(p->right))+1;
    y->h = max(inaltime(y->left), inaltime(y->right))+1;

    return y;
}

int Bal(nod* p)
{
    if (p==NULL)
        return 0;
    return inaltime(p->left) - inaltime(p->right);
}

nod* adauga_nod(nod* p,int val)
{
    if (p == NULL)
        return(nod_nou(val));

    if (val < p->info)
        p->left  = adauga_nod(p->left, val);
    else if (val > p->info)
        p->right = adauga_nod(p->right, val);
    else
        return p;

    p->h = 1 + max(inaltime(p->left),inaltime(p->right));


    int bal = Bal(p);


    if (bal > 1 && val < p->left->info)
        return Rotatie_Dreapta(p);

    // Caz dreapta dreapta
    if (bal < -1 && val > p->right->info)
        return Rotatie_Stanga(p);

    // Caz stanga dreapta
    if (bal > 1 && val > p->left->info)
    {
        p->left =  Rotatie_Stanga(p->left);
        return Rotatie_Dreapta(p);
    }

    // Caz dreapta stanga
    if (bal < -1 && val < p->right->info)
    {
        p->right = Rotatie_Dreapta(p->right);
        return Rotatie_Stanga(p);
    }

    return p;
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

nod* minim(nod* p)
{
    nod* current = p;
    while (current->left != NULL)
        current = current->left;

    return current;
}

nod* sterge(nod* root,int val)
{
    if (root == NULL)
        return root;

    if ( val < root->info )
        root->left = sterge(root->left, val);

    else if( val > root->info )
        root->right = sterge(root->right, val);

    else
    {
        if((root->left == NULL) || (root->right == NULL))
        {
            nod *temp = root->left ? root->left : root->right;

            if (temp == NULL)  //niciun copil
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;   //un copil -- il copiem
             delete(temp);
        }
        else
        {
            //nod cu doi copii -- cel mai mic din sub-arborele drept
            nod* temp = minim(root->right);

            // copiem succesorul si apoi il stergem
            root->info = temp->info;
            root->right = sterge(root->right, temp->info);
        }
    }

    if(root==NULL)
      return root;

    //actualizam inaltimea nodului
    root->h = 1 + max(inaltime(root->left),inaltime(root->right));

    // verificam inaltimea pentru a stii daca nodul e balansat
    int bal = Bal(root);

    // Daca nodul nu e balansa avem 4 cazuri:

    // Cas stanga stanga
    if (bal>1 && Bal(root->left)>=0)
        return Rotatie_Dreapta(root);

    // Caz stanga dreapta
    if (bal>1 && Bal(root->left)<0)
    {
        root->left = Rotatie_Stanga(root->left);
        return Rotatie_Dreapta(root);
    }

    // Caz dreapta dreapta
    if (bal<-1 && Bal(root->right)<=0)
        return Rotatie_Stanga(root);

    // Caz dreapta stanga
    if (bal<-1 && Bal(root->right)>0)
    {
        root->right = Rotatie_Dreapta(root->right);
        return Rotatie_Stanga(root);
    }

    return root;
}


void afisare(nod *p)
{
    if(p!=NULL)
    {
        afisare(p->left);
        cout<<p->info<<" ";
        afisare(p->right);
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

int main()
{
    nod *p;
    root= new nod;
    root=NULL;

    int i,n,k,a,g;

    cout<<"Cate noduri are arborele binar de cautare AVL?"<<endl;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"Introduceti cheia nodului: ";
        cin>>k;
        root=adauga_nod(root,k);
    }

     cout<<endl<<"Arborele afisat cu noduri in ordine crescatoare este: "<<endl;
     afisare(root);

     cout<<endl<<endl<<"Introduceti cheia elementului de cautat. "<<endl;
     cin>>a;
     if(cautare(root,a))
     cout<<"Elementul se afla in arbore!"<<endl<<endl;
     else
     cout<<"Elementul NU se afla in arbore!"<<endl<<endl;

     if(findMax(root))
    {
        cout<<"Maximul din arbore este: ";
        cout<<findMax(root);
        cout<<endl<<endl;
    }
    else
        cout<<"Nu exista maxim!"<<endl<<endl;

    cout<<"Inserati cheia elementului pe care doriti sa il stergeti: ";
    cin>>g;
    root=sterge(root,g);
    cout<<endl<<endl;

    cout<<"Arborele este: ";
    afisare_rsd(root);
    cout<<endl;
}
