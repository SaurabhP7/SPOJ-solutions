#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


int a[101] ;




void solve(int y){
	
	cout<<a[y]<<"\n" ;


}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	a[0]=0 ;
	a[1]=1 ;
	ll sum=1 ;
	for(ll i=2;i<=100;i++){
		sum=sum+(i*i)  ; ;
		a[i]=sum ;
	}


	int y ;
	
	//y=1 ;
	cin>>y ;
	

	while(y!=0){
		solve(y) ;
		cin>>y ;
	}
	
}