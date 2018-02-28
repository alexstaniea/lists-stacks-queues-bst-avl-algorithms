#include <stdio.h>
#include <stdlib.h>

int grad(int x, int n,int a[100][100])
{
    int i,s=0;
    for(i=1;i<=n;i++)
        s+=a[x][i];

    return s;
}

int nrmuchii(int n,int a[100][100])
{
    int i,j,nr=0;

    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i][j]==1)
              nr++;

    return nr;
}

void gradmax(int n,int a[100][100])
{
    int i;
    int max=grad(1,n,a);

    for(i=2;i<=n;i++)
        if(grad(i,n,a)>max)
            max=grad(i,n,a);

    printf("Varfurile de grad maxim sunt: ");

    for(i=1;i<=n;i++)
    {
        if(grad(i,n,a)==max)
            printf("%d ",i);
    }
    printf("\n");
}



int main()
{
       FILE *f;
       f=fopen("date.txt","r");
       int nrvf,i,j,a[100][100];

       fscanf(f,"%d",&nrvf);

       for(i=1;i<=nrvf;i++)
         for(j=1;j<=nrvf;j++)
       {
           fscanf(f,"%d",&a[i][j]);
       }

       for(i=1;i<=nrvf;i++)
            printf("Gradul varfului %d este: %d \n",i,grad(i,nrvf,a));

       printf("\n");

       printf("Graful are %d muchii!\n\n",nrmuchii(nrvf,a));

       gradmax(nrvf,a);
}
