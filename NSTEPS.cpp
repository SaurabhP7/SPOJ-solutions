#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void check(int x,int y,int *a,int *b){
	if(x-y==2){
		cout<<b[x]<<"\n" ;
	}
	else if(x==y){
		cout<<a[y]<<"\n" ;
	}
	else{
		cout<<"NO Number"<<"\n" ;
	}
}

void solve(){
	int a[100001] ;
	a[0]=0 ;
	for(int i=1;i<10001;i++){
		if(i%2==0)
			a[i]=a[i-1]+3 ;
		else
			a[i]=a[i-1]+1 ;
	}
	int b[10001] ;
	b[0]=b[1]=-1 ;
	b[2]=2 ;
	for(int i=3;i<10001;i++){
		if(i%2==0)
			b[i]=b[i-1]+3 ;
		else
			b[i]=b[i-1]+1 ;
	} 

	int N ;
	cin>>N ;
	while(N--){
		int l,r ;
		cin>>l>>r ;
		check(l,r,a,b) ;
	}


}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	y=1 ;
	//cin>>y ;
	while(y--){
		solve() ;
	}
	
}