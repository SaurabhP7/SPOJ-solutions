#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

bool valid(ll x,ll m,ll *a,ll n){

	ll sum=0 ;

	for(ll i=0;i<n;i++){

		if(a[i]>x){

			sum=sum+(a[i]-x) ;
		}

	}

	if(sum>=m)
		return true ;
	else
		return false ;

}

void solve(){

	ll n,m ;

	cin>>n>>m ;

	ll a[n] ;

	for(ll i=0;i<n;i++){
		cin>>a[i] ;
	} 

	sort(a,a+n) ;
	

	ll x=-1 ;
	for(ll b=a[n-1];b>=1;b/=2){

		while(valid(x+b,m,a,n)){
			x=x+b ;
		}

	}

	cout<<x ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	

	ll y ;

	y=1 ;
	//cin>>y ;
	
	while(y--)
	{	
		solve() ;

	}

}
