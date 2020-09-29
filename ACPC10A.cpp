#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(ll a,ll b ,ll c){

	ll a1=abs(b-a) ;
	ll a2=abs(c-b) ;

	if(a1==a2){

		cout<<"AP "<<c+a1<<"\n" ;

	}
	else{

		ll q=b/a ;
		cout<<"GP "<<c*q<<"\n" ;
	}
	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif


	//ll y ;
	//y=1 ;
	ll a,b,c ;
	cin>>a>>b>>c ;

	while(a!=0||b!=0||c!=0){
		solve(a,b,c) ;
		cin>>a>>b>>c ;
	}

	
}