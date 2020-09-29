#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mod 1000000007 

void dijkstra(vector<vector<pair<int,int>>> &adj,int n,int source,int timer){

	int dist[n+1] ;
	bool processed[n+1] ;

	for(int i=1;i<=n;i++){
		processed[i]=false ;
	}

	for(int i=1;i<=n;i++){
		dist[i]=1e9 ;
	}

	dist[source]=0 ;

	priority_queue<pair<int,int>> q ;

	q.push({0,source}) ;

	while(!q.empty()){

		int a=q.top().second ;
		q.pop() ;


		if(processed[a]){
			continue ;
		}

		processed[a]=true ;

		for(auto u:adj[a]){

			int b=u.first ;
			int w=u.second ;

			if(dist[a]+w<dist[b]){
				dist[b]=dist[a]+w ;
				q.push({-dist[b],b}) ;
			}

		}

	}

	int ans=0 ;

	for(int i=1;i<=n;i++)
	{
		if(dist[i]<=timer){
			ans++ ;
		}
	}

	cout<<ans ;

}

void solve(){

	int n ;
	cin>>n ;

	int exit_cell ;
	cin>>exit_cell ;

	int timer ;
	cin>>timer ;

	int e ;
	cin>>e ;

	vector<vector<pair<int,int>>> adj(n+1) ;

	for(int i=1;i<=e;i++){

		int l,r,w ;
		cin>>l>>r>>w ;

		adj[r].push_back({l,w}) ;

	}

	dijkstra(adj,n,exit_cell,timer) ;


	/*
	for(int i=1;i<=n;i++){
		for(auto c:adj[i]){
			cout<<i<<"->" ;
			cout<<c.first<<" "<<c.second<<"\n" ;

		}
	}
	*/

	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	y=1 ;
	//cin>>y ;
	
	while(y--)
	{		
		solve() ;
	}

}