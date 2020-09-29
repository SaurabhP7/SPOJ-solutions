#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


/*
	greedy- fails here

	int n ;
	cin>>n ;

	int a[n+1] ;

	a[0]=0 ;

	for(int i=1;i<=n;i++){
		cin>>a[i] ;
	}

	int ans=0 ;

	int i=1 ;
	int j=n ;

	int count=1 ;

	while(i<=j){
		if(a[i]<a[j]){

			ans=ans+a[i]*count ;
			i++ ;
			count++ ;
		}
		else{
			ans=ans+a[j]*count ;
			j-- ;
			count++ ;

		}
		cout<<ans<<"\n" ;
	}

	cout<<ans ;
*/

int n ;
int a[2000] ;
int cache[2000][2000] ;

int treat(int year,int be,int en){

	if(cache[be][en]!=0){
		return cache[be][en] ;
	}

	if(be>en){
		return 0 ;
	}

	else{

		return cache[be][en]=max(treat(year+1,be+1,en)+year*a[be],treat(year+1,be,en-1)+year*a[en]) ;

	}

}


void solve(){

	cin>>n ;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int ans=treat(1,0,n-1) ;
	cout<<ans ;

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