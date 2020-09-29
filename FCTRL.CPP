#include<iostream>

using namespace std ;

int fact(int n)
{  int count=0 ;
    for(int i=5;i<=n;i=i*5)
    {
          count=count+(n/i) ;

    }
    return count ;
}

int main()
{ int n;
cin>>n ;
int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i] ;
}
int ans[n] ;
for(int i=0;i<n;i++)
{

ans[i]=fact(a[i]) ;
}
for(int i=0;i<n;i++)
{
    cout<<ans[i]<<"\n";
}
}
