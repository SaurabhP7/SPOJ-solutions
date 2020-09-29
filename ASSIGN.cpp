#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int n;
int a[20][20] ;
ll allmask ;
ll dp[1<<20] ;

ll countWays(int mask){

	int idx=__builtin_popcount(mask) ;

	if(idx==n&&mask==allmask){
		return 1 ;

	}

	if(dp[mask]!=-1){
		return dp[mask] ;
	}

	ll ways=0 ;

	for(int j=0;j<n;j++){


		if(!a[idx][j])
			continue ;

		if(mask&1<<j)
			continue ;

		else 
			ways+=countWays(mask|1<<j) ;
	}

	dp[mask]=ways ;

	return dp[mask] ;

}


void solve(){
	

	memset(dp,-1,sizeof(dp)) ;

	cin>>n ;	

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j] ;
		}

	}

	allmask=pow(2,n)-1 ;

	ll ans=countWays(0) ;	
	
	cout<<ans<<"\n" ;

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