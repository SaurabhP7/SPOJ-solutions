#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	ll n ;
	cin>>n; 

	ll ans=(n*(n+2)*((2*n)+1))/8 ;
	cout<<ans<<"\n" ;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	cin>>y ;
	
	while(y--)
	{	
		solve() ;
	}

}