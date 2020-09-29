#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int H,W ;
vector<string> grid ;

bool inside_grid(int row,int col)
{
	return (0<=row && row<H && 0<=col && col<W) ;
}


vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}} ;

int dfs(int row,int col,char ch,vector<vector<bool>> &visited){

	pair<int,int> p=make_pair(row,col) ;
	visited[row][col]=true ;

	int mx=0 ;

	for(pair<int,int> dir:directions){

		int new_row=p.first+dir.first ;
		int new_col=p.second+dir.second ;

		if(inside_grid(new_row,new_col) && !visited[new_row][new_col] && grid[new_row][new_col]==ch+1){

			 int y=dfs(new_row,new_col,ch+1,visited) ;
			 mx=max(y,mx) ;
		}
	}

	return mx+1 ; 
	
}

void solve(int i){

	grid.clear() ;

	for(int i=0;i<H;i++){
		string s ;
		cin>>s ;
		grid.push_back(s) ;
	}

	/*
	for(int i=0;i<H;i++){
		cout<<grid[i]<<"\n" ;
	}
	*/
	vector<vector<bool>> visited(H,vector<bool>(W)) ;
	/*	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout<<visited[i][j]<<" " ;
		}
		cout<<"\n" ;
	}
	*/
	
	int ans=0 ;

	for(int row=0;row<H;row++){
		for(int col=0;col<W;col++){

			if(grid[row][col]=='A')
			{
				int x=dfs(row,col,'A',visited) ;
				
				if(x>ans){
					ans=x ;
				}

			}

			for(int i=0;i<H;i++){
				for(int j=0;j<W;j++){
					visited[i][j]=false ;
				}
			}
		}
	}
	
	cout<<"Case "<<i<<": "<<ans<<"\n" ;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif


	int i=1 ;
	
	while(cin>>H>>W)
	{	
		if(H==0&&W==0)
		{
			break ;
		}

		solve(i) ;
		i++ ;
	}
}