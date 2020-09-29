#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){


	ll n,q ;
	cin>>n>>q ;
	ll a[n+1] ;
	memset(a,0,sizeof(a)) ;

	for(ll i=1;i<=q;i++){

		ll l,r,num ;
		cin>>l>>r>>num ;
		a[l]=a[l]+num ;
		a[r+1]=a[r+1]-num ;
				
	}

	for(ll i=1;i<=n;i++){
		a[i]=a[i-1]+a[i] ;
	}


	ll m ;
	cin>>m ;

	for(ll i=1;i<=m;i++){
		ll t ;
		cin>>t ;
		cout<<a[t]<<"\n" ;

	}



}	


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	ll y ;

	//y=1;
	cin>>y ;

	while(y--){

		solve() ;

	}

}