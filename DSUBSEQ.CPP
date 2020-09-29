#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define MOD 1000000007 

void solve(){

	string s ;
	cin>>s ;

	int n=s.length() ;

	ll dp[n+1] ;

	dp[0]=1 ;

	map<char,int> prev ;

	for(int i=0;i<n;i++){

		prev[s[i]]=-1 ;

	}

	for(int i=0;i<n;i++){

		dp[i+1]=(dp[i]*2)%MOD ;

		if(prev[s[i]]!=-1)
		dp[i+1]=((dp[i+1]-dp[prev[s[i]]])%MOD+MOD)%MOD ;	

		prev[s[i]]=i ;

	}

	cout<<dp[n]<<"\n" ;

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