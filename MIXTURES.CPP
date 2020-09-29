#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int mix[100] ;

ll csum(int i,int j){

	ll sum=0 ;

	for(int k=i;k<=j;k++)
		sum=sum+mix[k] ;

	return sum%100 ;

}


void solve(int n){

	for(int i=1;i<=n;i++){
		cin>>mix[i] ;
	}

	n=n+1 ;

	ll dp[n][n] ;

	ll min ;

	memset(dp,0,sizeof(dp)) ;

	for(int d=1;d<n-1;d++){

		for(int i=1;i<n-d;i++){
			
			int j=i+d ;

			min=100000007 ;

			for(int k=i;k<=j-1;k++){

				int q=dp[i][k]+dp[k+1][j]+csum(i,k)*csum(k+1,j) ;
				
				if(q<min){
					min=q ;
				}

			}

		dp[i][j]=min ;	

		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" " ;
		}
		cout<<"\n" ;
	}
	

	//cout<<csum(0,1)<<"\n" ;

	cout<<dp[1][n-1]<<"\n" ;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif


	ll y ;
	
	//y=1 ;
	
	while(cin>>y){
		solve(y) ;
	}

	
}