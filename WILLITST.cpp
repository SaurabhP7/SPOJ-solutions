#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

bool isPowerof2(ll n){
	if(n==0){
		return 0 ;
	}
	else{

		while(n!=1){
		if(n%2!=0)
			return 0 ;
		n=n/2 ;
		}
	}

	return 1 ;
}

void solve(){

	ll n;
	cin>>n ;

	bool k=isPowerof2(n) ;

	if(k==true){
		cout<<"TAK" ;
	}
	else
	{
		cout<<"NIE" ;
	}


}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;
	
	y=1 ;
	//cin>>y ;
	
	while(y--){
	
		solve() ;

	}

	
}