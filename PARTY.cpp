#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

	
void solve(int x,int y){

	vector<pair<int,int>> p ;

	for(int i=0;i<y;i++){
		int l,r;
		cin>>l>>r ; 
		p.push_back(make_pair(l,r)) ;
	}
	
	sort(p.begin(),p.end()) ;
	

	int val[y] ;
	int wt[y] ;
	int W=x ;

	
	for(int i=0;i<y;i++){
		wt[i]=p[i].first	;
		val[i]=p[i].second ; 
	}

	
	int dp[y+1][W+1] ;
	
	for(int i=0;i<=y;i++){

		for(int j=0;j<=W;j++){

			if(i==0||j==0){
				dp[i][j]=0 ;
				continue ;
			}

			if(j<wt[i-1]){
				dp[i][j]=dp[i-1][j] ;
			}
			else{

				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]) ;

			}


		}
	}
	/*
	for(int i=0;i<=y;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" " ;
		}
	cout<<"\n" ;
	}
	*/
	
	
	int ans ;
	
	for(int i=0;i<=W;i++){

		if(dp[y][W]==dp[y][i]){
			ans=i ;
			break ;
		}
	}


	cout<<ans<<" "<<dp[y][W]<<"\n" ;


}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	pair<int,int> y ;
	cin>>y.first>>y.second ;

	while(y.first!=0&&y.second!=0){
		solve(y.first,y.second) ;
		cin>>y.first>>y.second ;
	
	}

	
}