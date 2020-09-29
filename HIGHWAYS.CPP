#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void dijkstra(vector<vector<pair<int,int>>> &adj, int n,int source,int dest){

	int dist[n+1] ;

	for(int i=1;i<=n;i++){
		dist[i]=1e9 ;
	}

	priority_queue<pair<int,int>> q  ;

	dist[source]=0 ;

	q.push({0,source}) ;

	bool processed[n+1] ;

	for(int i=1;i<=n;i++){
		processed[i]=false ;
	}

	while(!q.empty())
	{

		int a=q.top().second ;
		q.pop() ;

		if(processed[a]==true){
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
	/*
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" " ; 
	}
	cout<<"\n" ;
	*/
	
	if(dist[dest]==1e9){
		cout<<"NONE"<<"\n" ;
	}
	else
	{
		cout<<dist[dest]<<"\n" ;
	}
	

}

void solve(){

	int n,e,source,dest ;
	cin>>n>>e>>source>>dest ;

	vector<vector<pair<int,int>>> adj(n+1) ;

	for(int i=1;i<=e;i++){
		int c1,c2,time ;
		cin>>c1>>c2>>time ;

		adj[c1].push_back({c2,time}) ;
		adj[c2].push_back({c1,time}) ;
	}

	dijkstra(adj,n,source,dest) ;

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