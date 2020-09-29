#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define MOD 1000000007 

void solve(){

	
	int n ;
	cin>>n ;


	int i=1 ;
	int j=1 ;


	int ans=0 ;

	while(i<=n&&j<=n){

		while(i*j<=n){
			ans++ ;
			j++ ;
		}

		i++ ;
		j=i ;

	}

	cout<<ans ;

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