#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mod 1000000007 


void solve(int n,int e){

	double dist[n][n] ;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=0 ;	
		}
	}

	for(int i=1;i<=e;i++){

		int l,r ; 
		double w ;
		cin>>l>>r>>w ;

		dist[l-1][r-1]=w/100 ;
		dist[r-1][l-1]=w/100 ;
		
	}

	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=max(dist[i][j],dist[i][k]*dist[k][j]) ;	
			}
		}
	}

	cout<<fixed<<setprecision(6)<<dist[0][n-1]*100.0<<" percent" <<"\n" ;

	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	//y=1 ;
	//cin>>y ;

	int n,e ;
	
	while(cin>>n>>e)
	{		
		if(n==0)
			break;
		solve(n,e) ;
	}

}