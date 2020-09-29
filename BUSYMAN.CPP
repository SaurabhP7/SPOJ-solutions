#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


bool compareFunc(const pair<int,int>&a,const pair<int,int>&b)
{

	return a.second<b.second ;

}


void solve(){

	int n ;
	cin>>n ;

	vector<pair<int,int>> v ;


	while(n--){
		int x , y ;
		cin>>x>>y ;
		v.push_back(make_pair(x,y)) ;
	}


	sort(v.begin(),v.end(),compareFunc) ;



	int ans=0 ;
	int y=-1 ;

	for(auto iter:v){

		//cout<<iter.first<<" "<<iter.second<<"\n" ;
		
		if(iter.first>=y){
			y=iter.second ;
			ans++ ;
		}
		
		//cout<<y<<"\n" ;

	}

	cout<<ans<<"\n" ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;

	//y=1 ;
	cin>>y ; 

	while(y--){

		solve() ;
	}

}