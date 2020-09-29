#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

#define MOD 1000000007 

void solve(){

	string s ;
	cin>>s ;

	vector<int> num ;
	vector<int> sign ;

	
	int m=s.size() ;

	for(int i=0;i<m;i++){

		if(i%2==0){

			num.push_back(s[i]-48) ;
		}
		else{

			if(s[i]=='+'){
				sign.push_back(0) ;
			}
			else{
				sign.push_back(1) ;
			}
		}
	}

	int n=num.size() ;

	int dp[n][n] ;

	memset(dp,0,sizeof(dp)) ;

	for(int i=0;i<n;i++){
		dp[i][i]=num[i]  ;
	}

	for(int z=1;z<n;z++){
		for(int i=0;i+z<n;i++){
			int j=i+z ;

			int mx=0 ;
			for(int k=i;k<j;k++){

				if(sign[k]==0)
					mx=max(mx,dp[i][k]+dp[k+1][j]) ;
				else
					mx=max(mx,dp[i][k]*dp[k+1][j]) ;	
				
			}

			dp[i][j]=mx ;

		}

	}


	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" " ;

		}
		cout<<"\n" ;
	}	
	*/

	int dp2[n][n] ;

	memset(dp2,0,sizeof(dp)) ;

	for(int i=0;i<n;i++){
		dp2[i][i]=num[i]  ;
	}

	for(int z=1;z<n;z++){
		for(int i=0;i+z<n;i++){
			int j=i+z ;

			int mx=MOD ;
			for(int k=i;k<j;k++){

				if(sign[k]==0)
					mx=min(mx,dp2[i][k]+dp2[k+1][j]) ;
				else
					mx=min(mx,dp2[i][k]*dp2[k+1][j]) ;	
				
			}

			dp2[i][j]=mx ;

		}

	}

	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp2[i][j]<<" " ;

		}
		cout<<"\n" ;
	}	
	*/
	cout<<dp[0][n-1]<<" "<<dp2[0][n-1]<<"\n" ;

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