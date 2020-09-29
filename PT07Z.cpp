#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

struct details{

	int n ;
	queue<int> q ;
	vector<bool> used ; 
	vector<int> p ;
	vector<int> dis ;

};

struct node{
	int val;
	int dist ;
};

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

	

node BFS(vector<vector<int>> &adj,int n,int s,details s3){

	s3.n=n ;
	for(int i=1;i<=s3.n;i++)
		s3.used.push_back(false) ;

	for(int i=1;i<=s3.n;i++)
		s3.p.push_back(0) ;

	for(int i=1;i<=s3.n;i++)
		s3.dis.push_back(0) ;
	
	s3.q.push(s) ;
	s3.used[s]=true ;
	s3.p[s]=-1 ;

	node max ;
	max.val=s ;
	max.dist=0 ;

	int m=s ;
	while(!s3.q.empty()){

		int v=s3.q.front() ;
		s3.q.pop() ;

		for(int u: adj[v]){

			if(!s3.used[u])
			{
				s3.used[u]=true ;
				s3.q.push(u) ;
				s3.dis[u]=s3.dis[v]+1 ;
				m=u ;
				s3.p[u]=v ;
			}

		}

	}

	max.val=m ;
	max.dist=s3.dis[m] ;

	return max ;

}

void print_path(int u,details &s1){

	if(s1.used[u]==false){
		cout<<"No such path exists" ;

	}
	else{

		vector<int> path ;

		for(int v=u;v!=-1;v=s1.p[v]){

			path.push_back(v) ;

		}

		reverse(path.begin(),path.end()) ;

		cout<<"Path :" ;

		for(int i : path){
			cout<<i<<" " ;
		}

	}

}

void solve(){

	int V ;
	cin>>V ;
	if(V==0)
		{
			cout<<0 ;
			return ;
 		} 
	vector<vector<int>> adj(V+1) ;
	int l,r ;
	int q ;
	while(cin>>l>>r){
		addedge(adj,l,r) ;
		q=l ;
	}

	
	//printGraph(adj,V) ; 
	
	
	
	details s1 ;

	s1.n=V ;
	for(int i=1;i<=s1.n;i++)
		s1.used.push_back(false) ;

	for(int i=1;i<=s1.n;i++)
		s1.p.push_back(0) ;

	for(int i=1;i<=s1.n;i++)
		s1.dis.push_back(0) ;



	node b=BFS(adj,V,q,s1) ;
    //cout<<b<<"\n" ;

	int w=b.val ;
	int y=b.dist ;

	details s2 ;
	s2.n=V ;
	
	for(int i=1;i<=s2.n;i++)
		s2.used.push_back(false) ;
		
	for(int i=1;i<=s2.n;i++)
		s2.p.push_back(0) ;

	for(int i=1;i<=s2.n;i++)
		s2.dis.push_back(0) ;	

	node ans=BFS(adj,V,w,s2) ;

	cout<<ans.dist ;

//	print_path(3,s1) ;	
	






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