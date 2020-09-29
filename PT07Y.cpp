#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void addedge(vector<vector<int>> &adj,int u,int v){

	adj[u].push_back(v) ;
	adj[v].push_back(u) ;

}

void printGraph(vector<vector<int>> &adj,int V){

	for(int v=1;v<=V;v++){

		cout<<"Adjacency List vertex"<<v ;
		for(auto x:adj[v]) {

			cout<<"->"<<x<<"\n" ;

		}

	}

}

bool DFS(vector<vector<int>> &adj,int V,int v,vector<int> &color,vector<int> &parent,int &cycle_start,int &cycle_end,int p){

	color[v]=1 ;

	for(int u: adj[v]){

		if(color[u]==0){
			parent[u]=v ;
			p=v ;
			if(DFS(adj,V,u,color,parent,cycle_start,cycle_end,p)){
				return true ;
			}
		}
		else if(u!=p && color[u]==1){

			cycle_start=u ;
			cycle_end=v ;
		
			return true ;


		}


	}

	color[v]=2 ;
	return false ;

}


void findCycle(vector<vector<int>> &adj,vector<int> &color,vector<int> &parent,int &cycle_start,int &cycle_end,int V)
{
	for(int v=1;v<=V;v++){
		if(color[v]==0	&&	DFS(adj,V,v,color,parent,cycle_start,cycle_end,-1))
			break ;

	}

	if(cycle_start==-1){
		cout<<"YES" ;
	}
	else{
		cout<<"NO"<<"\n" ;
	}

}


void solve(){

int V,E ;
cin>>V>>E ;

vector<vector<int>> adj(V+1) ;


int l,r ;
int q ;
while(cin>>l>>r){
	addedge(adj,l,r) ;
}	

//printGraph(adj,V) ;


vector<int> color(V+1) ;
vector<int> parent(V+1) ;

for(int i=1;i<=V;i++){
	color[i]=0 ;
	parent[i]=-1 ;
}

int cycle_start, cycle_end ;
cycle_start=-1 ;

findCycle(adj,color,parent,cycle_start,cycle_end,V) ;



}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	y=1 ;

	while(y--){
		solve() ;
	}
	
}