#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int k,l,m ;
	cin>>k>>l>>m ;

	vector<int> tower ;

	for(int i=0;i<m;i++){
		int x ;
		cin>>x ;
		tower.push_back(x) ;
	}
	/*
	for(int i=0;i<m;i++){
		cout<<tower[i]<<" " ; 
	}
	cout<<"\n" ;
	*/
	
	for(int z=0;z<m;z++){
	
	char dp[tower[z]+1] ;

	dp[0]='x' ;

	for(int i=1;i<=k;i++){
		if(i==1||i==k){
			dp[i]='A' ;
		}
		else
		{
			if(dp[i-1]=='B')
				dp[i]='A' ;
			else
				dp[i]='B' ;

		}
	}

	for(int i=k+1;i<=l;i++){

		if(i==l){
			dp[i]='A' ;
		}
		else
		{
			if(dp[i-1]=='A' && dp[i-k]=='A')
				dp[i]='B' ;
			else
				dp[i]='A' ; 
		}

	}

	for(int i=l+1;i<=tower[z];i++){
		if(dp[i-1]=='A' && dp[i-k]=='A' && dp[i-l]=='A')
			dp[i]='B' ;
		else
			dp[i]='A' ;

	}

	/*
	for(int q=1;q<=tower[z];q++){
		cout<<dp[q]<<" " ;
	}
	cout<<"\n" ;
	*/

	if(dp[tower[z]]=='A'){
		cout<<'A' ;
	}
	else
	{
		cout<<'B' ;
	}

	}
	
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