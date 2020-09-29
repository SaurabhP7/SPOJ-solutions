#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(ll y){

	ll dp[y+1] ;

	dp[0]=0 ;
	dp[1]=1 ;
	
	for(ll i=2;i<=y;i++){

		dp[i]=max(i,(dp[i/2]+dp[i/3]+dp[i/4])) ;
 	}

 	cout<<dp[y]<<"\n" ;
	
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;
	//y=1 ;


	while (cin>>y)
	{	 
		solve(y) ;
	
	}
}