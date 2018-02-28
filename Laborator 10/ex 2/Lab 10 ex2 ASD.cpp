#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

ifstream f("date2.txt");

int a[100][100],n,m,x[100],p[100];

void citire()
{ int i,l,c;

  f>>n>>m;
  for(i=1;i<=m;i++)
  { f>>l>>c;
    a[l][c]=1;
    a[c][l]=1;
  }
}

void bf(int k)
{ int i,s,d;
  x[1]=k;
  p[k]=1;
  s=d=1;
  while(s<=d)
  { for(i=1;i<=n;i++)
     if(a[x[s]][i]==1 && !p[i])
	{ d++;
	  x[d]=i;
	  p[i]=1;
	}
    s++;
  }
  for(i=1;i<=d;i++) cout<<x[i]<<" ";
  cout<<endl;
}

int main()
{ citire();
  int i;
  for(i=1;i<=n;i++)
    if(!p[i]) bf(i);
}
