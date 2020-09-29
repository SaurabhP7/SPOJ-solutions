#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(double l){

	double ans ;

	ans=(l*l)/(2*3.1415926536) ;

	cout<<fixed<<setprecision(2)<<ans<<"\n" ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	

	ll y ;

	//y=1 ;
	
	while(cin>>y)
	{		
		if(y==0)
			break ;
		solve(y) ;

	}

}
