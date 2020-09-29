#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


int m, n;

int editDistance(string &s1,string &s2)
{
	m=s1.size() ;
	n=s2.size() ;

	int dp[m+1][n+1] ;

	for(int i=m;i>=0;i--){
		for(int j=n;j>=0;j--){
			if(i==m){
				dp[i][j]=abs(n-j) ;
			}
			else if(j==n){
				dp[i][j]=abs(m-i) ;
			}
			else{

				if(s1[j]==s2[i]){
					dp[i][j]=dp[i+1][j+1] ;
				}
				else{
					dp[i][j]=min(min(dp[i][j+1],dp[i+1][j]),dp[i+1][j+1])+1 ;
				}

			}
		}
	}
/*
	for(int i=0 ;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" " ;
		}
		cout<<"\n" ;
	}
*/

	return dp[0][0] ;

}


void solve(){


 string s1;
 string s2 ; 

 cin>>s1>>s2 ;

 int ans=editDistance(s1,s2) ; 

 cout<<ans<<"\n" ;	
	
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
//	y=1 ;
	cin>>y ;
	while(y--){
		solve() ;
	}
	
}