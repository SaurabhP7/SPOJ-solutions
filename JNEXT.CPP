n#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int n ; 

	cin>>n;

	int a[n] ;

	for(int i=0;i<n;i++){
		cin>>a[i] ;
	}

	bool x=next_permutation(a,a+n) ;
	
	if(x==false)
		cout<<-1<<"\n";
	else{
 
	for(int i=0;i<n;i++){
		cout<<a[i] ;
	}
	cout<<"\n" ;
	}

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