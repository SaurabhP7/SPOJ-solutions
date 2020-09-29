#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void unbounded_knapsnack(int W,int n,int *val,int *w){

	int dp[W+1] ;

	for(int i=1;i<=W;i++){
		dp[i]=1e9 ;
	}

	dp[0]=0 ;

	for(int i=1;i<=W;i++){
		for(int j=0;j<n;j++){

			if(w[j]<=i){
				dp[i]=min(dp[i],dp[i-w[j]]+val[j]) ;
			}

		}
	}

	if(dp[W]==1e9){
		cout<<"This is impossible."<<"\n" ;
		return ;
	}
	else
	{
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<"\n" ;
	}

}



void solve(){

	int l,h ;
	cin>>l>>h ;
	int W=h-l ;

	int n ;
	cin>>n ;

	int val[n] ;
	int w[n];
 
	for(int i=0;i<n;i++){

		int value,weight ;
		cin>>value>>weight ;

		val[i]=value ;
		w[i]=weight ;
	}

	unbounded_knapsnack(W,n,val,w) ;
		
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