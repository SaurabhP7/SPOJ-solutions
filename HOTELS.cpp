#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;

void solve(){

	ll n ;
	ll m ;
	cin>>n>>m ;

	ll a[n] ;

	for(ll i=0;i<n;i++){
		cin>>a[i] ;
	}

	int l=0;
	int r=0;

	ll sum=0 ;
	ll ans=0 ;

	while(l<n){

		while(sum+a[r]<=m && r<n){
			sum=sum+a[r] ;
			r++ ;
		}

		ans=max(ans,sum) ;
		sum=sum-a[l] ;		
		l++ ; 

	}

	cout<<ans ;

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