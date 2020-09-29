#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(ll count){

	ll n ;

	cin>>n ;

	if(n==0){
		cout<<"Case "<<count<<": "<<0<<"\n" ;
		return ;
	}


	ll num[n] ;

	for(ll i=0;i<n;i++){
		cin>>num[i] ;
	}

	ll dp[n] ;
	
	dp[0]=num[0] ;

	if(n==1){
		cout<<"Case "<<count<<": "<<dp[0]<<"\n" ;
		return ;
	}
	else{
		dp[1]=max(dp[0],num[1]) ;
		
		if(n==2){
			cout<<"Case "<<count<<": "<<dp[1]<<"\n" ;
			return ;
		}
		else{
			for(ll i=2;i<n;i++){
					dp[i]=max(dp[i-1],dp[i-2]+num[i]) ;
				}
		}	
	}
	cout<<"Case "<<count<<": "<<dp[n-1]<<"\n" ;	

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;
	
	//y=1 ;
	cin>>y ;
	ll count=1 ;
	while(count<=y){
	
		solve(count) ;
		count++ ;

	}

	
}