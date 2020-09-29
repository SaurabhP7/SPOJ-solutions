#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int R,C ;
int m[182][182] ;
int dist[182][182] ;


queue<int> rq ;
queue<int> cq ;

bool visited[182][182] ; 

int dr[4]={-1,+1,0,0} ;
int dc[4]={0,0,+1,-1} ;

void explore_neighbour(int r,int c,int &move_count,int &nodes_left_in_layer,int &nodes_in_next_layer){
	
	for(int i=0;i<4;i++){
		int rr=r+dr[i] ;
		int cc=c+dc[i] ;

		if(rr<0||cc<0)
			continue ;
		
		if(rr>=R||cc>=C)
			continue ;

		if(visited[rr][cc]==true){
			continue ;
		}

		if(m[rr][cc]==1){
			dist[rr][cc]=0 ;
			continue ;
		}


		rq.push(rr) ;
		cq.push(cc) ;
		visited[rr][cc]=true ;

		dist[rr][cc]=min(move_count,dist[rr][cc]) ;

		nodes_in_next_layer++ ;
	}

}


void problem(int sr,int sc,int move_count,int nodes_left_in_layer,int nodes_in_next_layer){

	rq.push(sr) ;
	cq.push(sc) ;

	visited[sr][sc]=true ;

	while(!rq.empty()){

		int r=rq.front() ;
		rq.pop() ;
		int c=cq.front() ;
		cq.pop() ;

		explore_neighbour(r,c,move_count,nodes_left_in_layer,nodes_in_next_layer) ;

		nodes_left_in_layer-- ;

		if(nodes_left_in_layer==0){
			nodes_left_in_layer=nodes_in_next_layer ;
			nodes_in_next_layer=0 ;
			move_count++ ;
		}

	}



}


string removeSpaces(string s){

	s.erase(remove(s.begin(),s.end(),' '),s.end()) ;
	return s ;
}
	
void solve(){

	queue<pair<int,int>> start ;

	cin>>R>>C;

	cin.ignore(numeric_limits<streamsize>::max(), '\n' );

	vector<string> v ;
	for(int i=0;i<R;i++){
    	
    	string str ;
		getline(cin,str) ;
		str=removeSpaces(str) ;
		v.push_back(str) ;

		
		for(int j=0;j<C;j++){
				m[i][j]=str[j]-'0' ;
					if(m[i][j]==1){
					start.push(make_pair(i,j)) ;
					}
			}

		}
/*
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<m[i][j]<<" " ;  
		}
		cout<<"\n" ;
	}	
*/

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			dist[i][j]=10000 ;
		}
	}

	while(!start.empty()){

		pair<int,int> p=start.front() ;
		
		int sr=p.first ;
		int sc=p.second ;
		
		dist[sr][sc]=0 ;	

		problem(sr,sc,1,1,0) ;

		start.pop() ;

		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				visited[i][j]=false ;
			}
		}

	}

	for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cout<<dist[i][j]<<" " ;
		}
		cout<<"\n" ;
	}

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	cin>>y ;
	while(y--){
		solve() ;
	
	}

	
}