#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(int x,int y){


	int a[x] ;
	int b[y] ;

	for(int i=0;i<x;i++){
		cin>>a[i] ;
	}

	for(int i=0;i<y;i++){
		cin>>b[i] ;
	}


	sort(a,a+x) ;
	sort(b,b+y) ;



	if(a[0]<b[0]||a[1]<b[1]||a[0]<b[1])
		cout<<"Y"<<"\n" ;
	else	
		cout<<"N"<<"\n" ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	

	ll x,y ;

	while(cin>>x>>y)
	{		
		if(x==0&&y==0)
			break ;
		solve(x,y) ;

	}

}
