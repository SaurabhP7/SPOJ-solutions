#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int m,n ;
	cin>>m>>n ;

	priority_queue<int> p1 ;
	priority_queue<int> p2 ;

	for(int i=0;i<m;i++)
	{	int x ;
		cin>>x ;
		p1.push(x)  ;
	}

	for(int i=0;i<n;i++)
	{	int x ;
		cin>>x ;
		p2.push(x)  ;
	}

	
	if(p2.top()>p1.top()){
		cout<<"MechaGodzilla"<<"\n" ;
	}
	else
	{
		cout<<"Godzilla"<<"\n" ;
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