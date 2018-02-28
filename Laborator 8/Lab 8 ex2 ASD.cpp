#include<iostream>
using namespace std;

void Merge(int v[], int s, int m, int d)
{
    int i,j,k;
    int n1 = m-s+1;
    int n2= d-m;

    int a[n1],b[n2];

    for(i=0;i<n1;i++)
        a[i]=v[s+i];

    for(j=0;j<n2;j++)
        b[j]=v[m+1+j];

    i=0;
    j=0;
    k=s;

    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            v[k]=a[i];
            i++;
        }
        else
        {
            v[k]=b[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        v[k]=a[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        v[k]=b[j];
        j++;
        k++;
    }
}

void MergeSort(int v[], int s, int d)
{
    if(s<d)
    {
        int m=(s+d)/2;
        MergeSort(v,s,m);
        MergeSort(v,m+1,d);

        Merge(v,s,m,d);
    }
}

int main()
{
    int v[100],i,n;

    cout<<"Introduceti lungimea vectorului: ";
    cin>>n;


    cout<<"Introduceti elementele vectorului: ";
    for(i=0;i<n;i++)
        cin>>v[i];

    MergeSort(v,0,n-1);

    cout<<"Vectorul sortat este: ";
    for(i=0;i<n;i++)
        cout<<v[i]<<' ';
}
