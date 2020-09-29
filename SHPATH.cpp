#include<bits/stdc++.h>
#include <sstream>
using namespace std ;
typedef long long ll ;

const int INF=1000000000 ;

void dijkstra(vector<vector<pair<int,int>>> adj, int s,int dest, vector<int> &d, vector<int> &p,int n){


	d.assign(n+1,INF) ;
	p.assign(n+1,-1) ;

	d[s]=0 ;
	using pii=pair<int,int> ;

	priority_queue<pii,vector<pii>,greater<pii>> q ;

	q.push({0,s}) ;

	while(!q.empty()){

		int v=q.top().second ;
		int d_v=q.top().first ;

		q.pop() ;

		if(d[v]!=d_v)
			continue ;

		for(auto edge:adj[v])
		{	
			int to=edge.first ;
			int len=edge.second ;

			if(d[v]+len<d[to]){
				d[to]=d[v]+len ;
				p[to]=v ;
				q.push({d[to],to}) ;
			}

		}
	}

	


}

void solve(){

	int n ;
	cin>>n ;

	vector<vector<pair<int,int>>> adj(n+1) ;
	
	map<string,int> map ;

	for(int i=1;i<=n;i++){

		string s ;
		cin>>s ;

		map[s]=i ;

		int e ;
		cin>>e ;

		for(int j=1;j<=e;j++){

			int b,w ;
			cin>>b>>w ; 
			adj[i].push_back(make_pair(b,w)) ;

		}
	}
	
	int q; 
	cin>>q ;

	int flag=0 ;

	for(int i=1;i<=q;i++){

		vector<int> d(n+1) ;
		vector<int> p(n+1) ;

		string sourceString,destString ;
		cin>>sourceString>>destString ;
		
		int source=map[sourceString] ;
		int dest=map[destString] ; 		
				

		dijkstra(adj,source,dest,d,p,n) ;
		cout<<d[dest]<<"\n" ;

	}



	/*
	for(int i=1;i<=n;i++){

		for(pair<int,int> p:adj[i]){

			cout<<i<<" is connected to "<<p.first<<" via "<<p.second<<"\n" ;

		}

	}
	*/
	/*
	for(int i=1;i<=n;i++){
		cout<<cities[i].first<<" "<<cities[i].second<<"\n" ;

	}
	*/

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll y ;

	//y=1 ;
	cin>>y ;
	
	while(y--)
	{	
		solve() ;

	}

}
