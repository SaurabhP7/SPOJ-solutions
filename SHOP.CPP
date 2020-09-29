#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

pair<int,int> directions[4]={{0,1},{1,0},{-1,0},{0,-1}} ;

bool isvalid(int x,int y,int r,int c){

	return x>=0 && y>=0 && x<r && y<c ;

}


int dijkstra(vector<string> &grid,pair<int,int> source,pair<int,int> destination,int r,int c){

	int distance[r][c] ;
	bool processed[r][c] ;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			distance[i][j]=1e9 ;
			processed[i][j]=false ;
		}
	}

	priority_queue<pair<int,pair<int,int>>> q ;

	distance[source.first][source.second]=0 ;
	//distance[destination.first][destination.second]=0 ;

	q.push({0,source}) ;

	while(!q.empty()){

		int ui=q.top().second.first ;
		int uj=q.top().second.second ;

		q.pop() ;

		if(processed[ui][uj]==true){
			continue ;
		}

		processed[ui][uj]=true ;

		for(auto dir:directions)
		{
			int vi=ui+dir.first ;
			int vj=uj+dir.second ;

			if(isvalid(vi,vj,r,c) && grid[vi][vj]!='X' && processed[vi][vj]!=true){
				int w ;
				if(vi==destination.first && vj==destination.second)
					 w=0 ;
				else	
				 	 w=grid[vi][vj]-'0' ;

				if(distance[ui][uj]+w<distance[vi][vj]){

					distance[vi][vj]=distance[ui][uj]+w ;
					q.push({-distance[vi][vj],{vi,vj}}) ;

				}
			}
		}	

	}

	/*
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<distance[i][j]<<" " ;
		}
		cout<<"\n" ;
	}
	
	*/

	return distance[destination.first][destination.second]  ;

}


void solve(int x,int y){

	int r=y ;
	int c=x ;

	vector<string> grid ;

	for(int i=0;i<r;i++){
		string s ;
		cin>>s ;
		grid.push_back(s) ;
	
	}

	int sx,sy,dx,dy ;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(grid[i][j]=='S')
			{	sx=i ;
				sy=j ;
			}
			if(grid[i][j]=='D')
			{
				dx=i ;
				dy=j ;
			}		
		}
	}

	pair<int,int> source={sx,sy} ;
	pair<int,int> destination={dx,dy} ;

	int ans=dijkstra(grid,source,destination,r,c) ;
	cout<<ans<<"\n" ;


}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int x,y ;

	//y=1 ;
	
	
	while(cin>>x>>y)
	{	
		if(x==0 && y==0)
			break ;
		solve(x,y) ;
	}

}