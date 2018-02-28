//LABORATOR 1- ALG&STRUCTDAT - ALEXANDRU STANIEA - GRUPA 132

/*  //sortare prin insertie
#include<iostream>
using namespace std;
int main()
{
    int i,j,n=4,v[5],x;

    for(i=0;i<n;i++)
        cin>>v[i];

    for(i=1;i<n;i++)
        {   j=i-1;
            x=v[i];
           while((v[j]>x)&&(j>=0))
           {v[j+1]=v[j];
           j--;}
         v[j+1]=x;
         }

        for(i=0;i<n;i++)
         cout<<v[i];


}   */



/*   //sortare prin selectie
#include<iostream>
using namespace std;
int main()
{
    int v[5],i,j,n=4,k;


    for(i=0;i<n;i++)
        cin>>v[i];


    for(i=0;i<n;i++)
        {k=i;
       for(j=i+1;j<n;j++)
        {if(v[j]<v[k])
          k=j;}
       swap(v[i],v[k]);}

    for(i=0;i<n;i++)
         cout<<v[i];

}
*/


/*   //cautare binara
#include<iostream>
using namespace std;
int main()
{
    int m,i,l=0,r=3,x,v[5],n=4;
    cin>>x;


    for(i=0;i<n;i++)
        cin>>v[i];


    m=(l+r)/2;

    while(l<r)
      {
        if(v[m]==x)
         {
         cout<<m;
         break;
         }
        else if(v[m]>x)
            r=m-1;
        else
            l=m+1;

         m=(l+r)/2;

       }


} */


/*  //bubblesort
#include<iostream>
using namespace std;
int main()

{
   int aux,i,j,n=4,v[5];

   for(i=0;i<n;i++)
        cin>>v[i];

   for(i=1;i<n;i++)
      {
          for(j=n;j>=i;j--)
           if(v[j]<v[j-1])
      {
       aux=v[j];
       v[j]=v[j-1];
       v[j-1]=aux;
      }

      }

      for(i=0;i<n;i++)
        cout<<v[i];

}  */





/*   //cautare secventiala
#include<iostream>
using namespace std;
int main()
{

    int x,i,n=4,v[5];
    bool gasit=false;
    cin>>x;

    for(i=0;i<n;i++)
        cin>>v[i];

     for(i=0;i<n;i++)
        if(v[i]==x)
            gasit=true;

    cout<<gasit;
}*/

