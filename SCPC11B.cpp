#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(int n){

	vector<int> stations ;


	for(int i=0;i<n;i++){
		
		int x;
		cin>>x ;
		stations.push_back(x) ;
	}
	
	sort(stations.begin(),stations.end()) ;

	/*
	for(int i=0;i<n;i++){
		cout<<stations[i]<<" " ;
	}
	cout<<"\n" ;
	*/


	for(int i=0;i<n-1;i++){


		if(stations[i+1]-stations[i]>200)
		{
			cout<<"IMPOSSIBLE"<<"\n" ;
			return ;
		}


	}

	if((1422-stations[n-1])*2>200)
		cout<<"IMPOSSIBLE"<<"\n" ;
	else
		cout<<"POSSIBLE"<<"\n" ;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	//cin>>y ;
	
	while(cin>>y)
	{	
		if(y==0)
			break ;
		solve(y) ;
	}


}