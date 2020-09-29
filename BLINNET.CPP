#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

struct Edge{

	int u,v,weight ;
	bool operator<(Edge const &other){
		return weight<other.weight ;
	}
};


void solve(){

	int n ;
	cin>>n ;

	//HOW MUCH MEMORY TO BE ASSOCIATED?
	vector<Edge> edges ;

	for(int i=1;i<=n;i++){

		string s ;
		cin>>s ;

		int e ;
		cin>>e ;

		for(int j=1;j<=e;j++){

			int other_vertex,edge_weight ;
			cin>>other_vertex>>edge_weight ;

			Edge x ;
			x.u=i ;
			x.v=other_vertex ;
			x.weight=edge_weight ;

			edges.push_back(x) ;

		}
	}

	int cost=0 ;
	vector<int> tree_id(n+1) ;

	for(int i=1;i<=n;i++){
		tree_id[i]=i ;
	}

	sort(edges.begin(),edges.end()) ;

	for(Edge e:edges){

		if(tree_id[e.u]!=tree_id[e.v]){

			cost+=e.weight ;

			int old_id=tree_id[e.u] ;
			int new_id=tree_id[e.v] ;

			for(int i=1;i<=n;i++){

				if(tree_id[i]==old_id)
				{
					tree_id[i]=new_id ;
				}

			}
		}

	}

	cout<<cost<<"\n" ;


}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	cin>>y ;

	while(y--)
	{		
		solve() ;

	}

}