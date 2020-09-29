#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


void solve(int overallcount){

	int x ;
	int n ;
	cin>>x>>n ;

	int a[n] ;
	for(int i=0;i<n;i++){
		cin>>a[i] ;
	}

	sort(a,a+n) ;

	int flag=0 ;
	int sum=0 ;

	int k=n-1 ;
	int count=0 ;

	while(k>=0){

		sum=sum+a[k] ;
		count++ ;	
		if(sum>=x) {
			flag++ ;
			break ;
		}
		k-- ;
	}

	if(flag==0){
		cout<<"Scenario #"<<overallcount<<":"<<"\n" ;
		cout<<"impossible"<<"\n" ;

	}
	else
	{	
		cout<<"Scenario #"<<overallcount<<":"<<"\n" ;
		cout<<count<<"\n" ;
	}	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	int y ;
	
	//y=1 ;
	cin>>y ;
	int count=1 ;
	while(count<=y){
		solve(count) ;
		count++ ;
	}

	
}