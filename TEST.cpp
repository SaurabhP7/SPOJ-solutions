#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;



void solve(int y){
	
	if(y==42){
		return ;
	}
	else{
		cout<<y<<"\n" ;
	}
	
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;

	while (cin>>y)
	{	 
		solve(y) ;
		if(y==42)
			return 0 ;
	}
}