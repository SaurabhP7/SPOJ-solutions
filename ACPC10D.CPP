#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(ll n,ll i){




	ll a[n][3] ;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			cin>>a[i][j] ;
		}
	}

	if(n==1){

		cout<<i<<". "<<a[0][1]<<"\n" ;
		return ;

	}


	a[0][2]=a[0][2]+a[0][1] ;
	a[1][0]=a[1][0]+a[0][1] ;
	a[1][1]=min(min(a[0][1]+a[1][1],a[1][0]+a[1][1]),a[0][2]+a[1][1]) ;
	a[1][2]=min(min(a[1][2]+a[0][1],a[1][1]+a[1][2]),a[0][2]+a[1][2]) ;

	
	for(ll i=2;i<n;i++){

	a[i][0]=min(a[i-1][0]+a[i][0],a[i-1][1]+a[i][0]);
	a[i][1]=min(min(a[i][0]+a[i][1],a[i][1]+a[i-1][2]),min(a[i-1][1]+a[i][1],a[i-1][0]+a[i][1])) ;
	a[i][2]=min(min(a[i-1][2]+a[i][2],a[i-1][1]+a[i][2]),a[i][2]+a[i][1]) ;

	}
	
	cout<<i<<". "<<a[n-1][1]<<"\n" ; 
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<" " ;

		}
		cout<<"\n" ;
	}
	*/
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll n ;
	ll i=1 ;

	while(cin>>n)
	{		
		if(n==0)
			break ;
	
		solve(n,i) ;

		i++ ;

	}

}