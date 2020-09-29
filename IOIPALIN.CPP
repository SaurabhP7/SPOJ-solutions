#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int n ;
	cin>>n ;

	string s ;
	cin>>s ;

	string rev_s=s ; 
	reverse(rev_s.begin(),rev_s.end()) ;

	int lcs[n+1][n+1] ;

	memset(lcs,0,sizeof(lcs)) ;

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){

			if(i==0||j==0){
				lcs[i][j]=0 ;
			}
			else{

				lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]) ;

				if(s[i-1]==rev_s[j-1])
				lcs[i][j]=max(lcs[i-1][j-1]+1,lcs[i][j]) ;

			}

		}
	}

	/*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<lcs[i][j]<<" " ;
		}
		cout<<"\n" ;
	}
	*/

	cout<<n-lcs[n][n] ;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}