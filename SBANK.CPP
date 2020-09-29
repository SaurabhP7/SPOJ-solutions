#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
 
 	int x ;
 	cin>>x ;
	cin.ignore() ; 		

 	vector<string> v ;

 	for(int i=0;i<x;i++){


 		string s ;
 		getline(cin,s) ;
 		v.push_back(s) ;
 	
 	}

 	map<string,int> m ;

 	for(int i=0;i<x;i++){

 		m[v[i]]++ ;

 	}


 	for(auto x : m){
 
 		cout<<x.first<<" "<<x.second<<"\n" ;
 
 	}
 	
 	cout<<"\n" ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	cin>>y ;
	cin.ignore() ; 		

	while(y--)
	{	
		solve() ;
	}

}