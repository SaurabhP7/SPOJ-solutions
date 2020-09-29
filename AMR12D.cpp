#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	string s ;
	cin>>s ;

	string temp=s;
	reverse(temp.begin(),temp.end()) ;

	if(s==temp)
		cout<<"YES"<<"\n" ;
	else
		cout<<"NO"<<"\n" ;

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