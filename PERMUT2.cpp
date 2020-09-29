#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mod 1000000007 

void solve(int n){

	int a[n+1] ;

	map<int,int> m ;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i] ;
		m[a[i]]=i ;
	}

	for(int i=1;i<=n;i++){

	}

	int b[n+1] ;

	for(int i=1;i<=n;i++){
		b[i]=m[i] ;
	} 


	for(int i=1;i<=n;i++){

		if(b[i]!=a[i])
			{cout<<"not ambiguous"<<"\n" ;
				return ;
			}

	}

	cout<<"ambiguous"<<"\n" ;
	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	//y=1 ;
	//cin>>y ;
	
	while(cin>>y)
	{		
		if(y==0)
			break;	
		solve(y) ;
	}

}