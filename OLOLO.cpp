#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	ll x ;

	cin>>x ;

	ll ans=0  ;


	for(ll q=0;q<x;q++){

		ll m ;
		cin>>m ;
		ans^=m ;

	}

	cout<<ans<<"\n" ;

	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;

	y=1 ;
	//cin>>y ;

	while(y--){

		solve() ;

	}

}