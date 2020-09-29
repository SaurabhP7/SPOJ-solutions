#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){


	int n ;
	cin>>n; 

	set<int> s ;

	vector<int> friends(n) ;

	int ans=0 ;

	for(int i=0;i<n;i++){

		int x ;
		cin>>x ;
		
		friends.push_back(x) ;

		int m ;
		cin>>m ;

		
		for(int i=0;i<m;i++){

			int var ;
			cin>>var ;

			s.insert(var) ;

		}

	}
	
	for(int i=0;i<friends.size();i++)
	{
		auto it=s.find(friends[i]) ;

			if(it!=s.end())
				s.erase(friends[i]) ;
	}		

	cout<<s.size() ;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	y=1 ;
	//cin>>y ;
	
	while(y--)
	{		
		solve() ;
	}

}