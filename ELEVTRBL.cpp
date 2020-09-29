#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int bfs(int floors,int source,int dest,int up,int down){

	int distance[floors+1] ;
	int visited[floors+1] ;

	for(int i=1;i<=floors;i++){
		distance[i]=-1 ;
		visited[i]=false ;
	}

	visited[source]=true ;
	distance[source]=0 ;

	queue<int> q ;

	q.push(source) ;

	while(!q.empty()){

		int curr=q.front() ;
		q.pop() ;

		if(curr+up<=floors && !visited[curr+up])
		{
			visited[curr+up]=true ;
			distance[curr+up]=distance[curr]+1 ;
			q.push(curr+up) ;

		}

		if(curr-down>=1 && !visited[curr-down])
		{
			visited[curr-down]=true ;
			distance[curr-down]=distance[curr]+1 ;
			q.push(curr-down) ;
		
		}
	
	}

	return distance[dest] ;

}


void solve(){

	int floors,source,dest,up,down ;
	cin>>floors>>source>>dest>>up>>down ;

	int x=bfs(floors,source,dest,up,down) ;
	if(x==-1){
		cout<<"use the stairs"<<"\n" ;
	} 
	else
	{
		cout<<x<<"\n" ;
	}
	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}