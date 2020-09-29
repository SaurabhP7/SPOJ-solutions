#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


void solve(int y){

	int a[y] ;

	for(int i=0;i<y;i++){
		cin>>a[i] ;
	}


	int ans=0 ;
	int sum=0 ;

	for(int i=0;i<y;i++){
		sum=sum+a[i] ;
	}

	if(sum%y==0){
		
		int n=sum/y ;

		sort(a,a+y) ;
		int ans=0 ;
		int i=0 ;
		while(a[i]<n){
			//cout<<ans<<"\n" ;
			int k=n-a[i] ;
			ans=ans+k ;
			i++ ;
			
		}

		cout<<ans<<"\n" ;
	}
	else
	{
		cout<<-1<<"\n" ;
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
	
	while(y!=-1){

		solve(y) ;
		cin>>y ;

	}

	
}