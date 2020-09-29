#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	ll n;
	cin>>n ;

	ll candy[n] ;
	for(ll i=0;i<n;i++){
		cin>>candy[i] ;
	}

	sort(candy,candy+n) ;


	ll sum=0 ;
	
	for(ll i=0;i<n;i++)
		sum=((sum%n)+(candy[i]%n))%n ;

	if(sum==0){
		cout<<"YES"<<"\n" ;
	}
	else{
		cout<<"NO"<<"\n" ;
	}
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;

	//y=1 ;
	cin>>y ;

	while(y--){

		solve() ;

	}



}