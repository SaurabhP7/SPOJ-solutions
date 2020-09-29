#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int addLetter(string s1,string s2){

	int m=s1.size() ;

	int dp[m+1][m+1] ;

	for(int i=m;i>=0;i--){
		for(int j=m;j>=0;j--){
			if(i==m||j==m){
				dp[i][j]=0 ;
			}
			else{

				if(s1[i]==s2[j]){
					dp[i][j]=dp[i+1][j+1]+1 ;
				}
				else{
					dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
				}
			}
		}
	}

	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){

			cout<<dp[i][j]<<" " ;

		}
		cout<<"\n" ;
	}


	return dp[0][0] ;


}

string reversestring(string s){

	int n=s.length() ;
	for(int i=0,j=n-1;i<=j;i++,j--){
		swap(s[i],s[j]) ;
	}

	return s ;
}


void solve(){
	string s1 ;
	cin>>s1 ;

	string s2=reversestring(s1) ;
	//cout<<s2<<"\n" ;
	
	int m=s1.size() ;

	int ans=addLetter(s1,s2) ;
 	cout<<m-ans<<"\n" ;


}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	
	y=1 ;
//	cin>>y ;
	
	while(y--){
		solve() ;
	}
	
}