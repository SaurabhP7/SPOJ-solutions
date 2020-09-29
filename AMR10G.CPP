#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	ll n,k ;
	cin>>n>>k ;

	ll a[n] ;

	for(ll i=0;i<n;i++){
		cin>>a[i] ;
	}

	if(k==1){
		cout<<0<<"\n" ;
		return ;
	}

		sort(a,a+n) ;
 
		ll i=0 ;
		ll j=k-1 ;

		ll min=1e9 ;

		ll diff ;

		while(j<n){

			diff=a[j]-a[i] ;

			if(diff<min){
				min=diff ;
			}

			i++ ;
			j++ ;


		}

		cout<<min<<"\n" ;
	
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;

	//y=1 ;
	cin>>y ;
	
	while(y--)
	{	 
		solve() ;
	}
}