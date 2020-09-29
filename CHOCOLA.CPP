#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int r,c ;
	cin>>r>>c ;

	priority_queue<pair<int,bool>> q ;

	for(int i=1;i<=r-1;i++){
		int x ;
		cin>>x ;
		q.push({x,true}) ;
	}

	for(int i=1;i<=c-1;i++){
		int x ;
		cin>>x ;
		q.push({x,false}) ;
	}

	int vertical=1,horizontal=1 ;
	int cost=0 ;

	while(!q.empty())
	{
		if(q.top().second==true)
		{
			cost=cost+(horizontal*q.top().first) ;
			vertical=vertical+1 ;
		}
		else{
			cost=cost+(vertical*q.top().first) ;
			horizontal=horizontal+1;
		}

		q.pop() ;
	}

	cout<<cost<<"\n" ;

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