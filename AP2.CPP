#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	ll a1,a2,a3 ;
	cin>>a1>>a2>>a3 ;

	ll k=a1+a2 ;

	ll n=(a3*2)/k ;

	ll w=a2-a1 ;

	ll d=w/(n-5) ;

	ll a=a1-(2*d) ;


	cout<<n<<"\n" ;
	for(ll i=0;i<=n-1;i++){
		cout<<a+(i*d)<<" " ;
	}
	cout<<"\n" ;


}

int main(){

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