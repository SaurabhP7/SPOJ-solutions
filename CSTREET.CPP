#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int INF = 1000000000;

struct Edge
{
	int w=INF,to=-1 ;
	bool operator<(Edge const& other) const{
		return make_pair(w,to)<make_pair(other.w,other.to) ;
	}	
};

int prim(vector<vector<Edge>> &adj,int n){

	int total_weight=0 ;
	vector<Edge> min_e(n+1) ;

	min_e[1].w=0 ;
	set<Edge> q ;
	q.insert({0,1}) ;

	vector<bool> selected(n+1,false) ;

	for(int i=1;i<=n;i++){

		int v=q.begin()->to ;
		selected[v]=true ;
		total_weight+=q.begin()->w ;
		q.erase(q.begin()) ;


		for(Edge e:adj[v]){

			if(!selected[e.to] && e.w<min_e[e.to].w)
			{
				q.erase({min_e[e.to].w,e.to}) ;
				min_e[e.to]={e.w,v} ;
				q.insert({e.w,e.to}) ;
			}
		
		}
	}

	return total_weight ;

}


void solve(){

	int p,n,m ;
	cin>>p>>n>>m ;

	vector<vector<Edge>> adj(n+1) ; 

	for(int i=1;i<=m;i++){

		int a,b,c ;
		cin>>a>>b>>c ;

		Edge x ;
		Edge y ;

		x.w=c ;
		x.to=b ;

		y.w=c ;
		y.to=a ;

		adj[a].push_back(x) ;
		adj[b].push_back(y) ;

	}
	
	int ans=prim(adj,n) ;
	cout<<ans*p<<"\n" ;		

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