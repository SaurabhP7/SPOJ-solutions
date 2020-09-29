#include<bits/stdc++.h>
using namespace std ;

void solve(double i){

	int n,k ;
	double final,time ;
	cin>>n>>k>>final>>time ;

	double x[n] ;

	for(int i=0;i<n;i++){
		cin>>x[i] ;
	}

	double v[n] ;

	for(int i=0;i<n;i++){
		cin>>v[i] ;
	}

	double final_dist[n] ;

	for(int i=0;i<n;i++){

		final_dist[i]=x[i]+(v[i]*time) ;

	}
	/*
	for(int i=0;i<n;i++){
		cout<<final_dist[i]<<" " ;
	}
	cout<<"\n" ;
	*/	
	
	stack<double> st ;

	int swap=0  ; 
	int count=0 ;

	for(int i=n-1;i>=0;i--){

		if(final_dist[i]>=final){
			swap+=st.size() ;
			count++ ;
			if(count==k)
				break ;
		}
		else{
			st.push(final_dist[i]) ;
		}
	} 

	if(count<k){
		cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<"\n" ;
	}
	else{
		cout<<"Case #"<<i<<": "<<swap<<"\n" ;
	}

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	double y ;

	//y=1 ;
	cin>>y ;
	double i=1 ;
	
	while(y--)
	{	
		solve(i) ;
		i++ ;
	}

}