#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;



void solve(){

	ll a,b ;
	cin>>a>>b ;

	ll res=1 ;

	while(b>0){

		if(b&1){
			res=(res*a)%10 ;
		}

		a=(a*a)%10 ;
		b=b>>1 ;

	}

	cout<<res<<"\n" ;



}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;

	//y=1 ;
	cin>>y ; 

	while(y--){

		solve() ;
	}

}