#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


void solve(){

	int n; 
	cin>>n ;
	int a[n],b[n] ;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	sort(a,a+n) ;
	sort(b,b+n) ;

	int sum=0 ;

	for(int i=0;i<n;i++){
		sum=sum+a[i]*b[i] ;
	}

	cout<<sum<<"\n" ;



}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;
	
	//y=1 ;
	cin>>y ;
	
	while(y--){
		solve() ;
	}

	
}