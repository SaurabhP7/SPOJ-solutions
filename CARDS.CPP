#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


void solve(){

	ll n ;
	cin>>n ;

	ll b=n-1 ;
	ll ans1=(b*(b+1))/2 ;

	ll ans2=n*(n+1) ;

	cout<<(ans1+ans2)%1000007<<"\n" ;
		
}	


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;

	//y=1;
	cin>>y ;

	while(y--){

		solve() ;

	}

}