//randomized quicksort + lomuto
#include <cstdlib>
#include <iostream>
using namespace std;

/* functia pozitioneaza elementele mai mici ca pivotul
(ales pe ultima pozitie) in stanga lui si pe cele mai mari
in dreapta */

/* cand gasim elemente mai mici decat pivotul
incepem sa le punem pe primele pozitii,
la sfarsit inlocuim pivotul cu elementul din mijloc */

int partitionare(int v[], int low, int high)
{
    int pivot = v[high]; //alegem pivotul pe ultima pozitie
    int i = (low - 1);   //indexul celui mai mic element

    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}

//genereaza un pivot aleator si il pune la sfarsit,
// dupa apeleaza functia de partitionare
int partitionare2(int v[], int low, int high)
{
    int random = low + rand() % (high - low);
    swap(v[random], v[high]);
    return partitionare(v, low, high);
}

void quickSort(int v[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionare2(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void afisare(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout<<v[i]<<" ";
}

int main()
{
    int i,n,v[100];
    cout<<"Cate elemente are vectorul de sortat?"<<endl;
    cin>>n;
    cout<<"Introduceti elementele"<<endl;

    for(i=0;i<n;i++)
        cin>>v[i];

    quickSort(v, 0, n - 1);
    cout<<"Vector sortat: "<<endl;
    afisare(v, n);
    return 0;
}
