#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int cache[1005][1005] ;

int ts(int h,int a,int check){


	if(h<=0||a<=0){
		return 0 ;
	}

	if(cache[h][a]!=-1){
		return cache[h][a] ;
	}

	//AIR
	if(check==1){     //+3,+2
		cache[h][a]=max(ts(h-5,a-10,2),ts(h-20,a+5,3)) ;
		return cache[h][a]+1 ;
	}

	//WATER
	else if(check==2){  //-5,-10
		cache[h][a]=ts(h+3,a+2,1) ;
		return cache[h][a]+1 ;
	}


	//FIRE
	else if(check==3) //-20,+5
	{
		cache[h][a]=ts(h+3,a+2,1) ;
		return cache[h][a]+1 ;
	}

}

void solve(){


	int h,a ;
	cin>>h>>a ;

	memset(cache,-1,sizeof(cache)) ;
	
	int ans1=ts(h+3,a+2,1) ;
	int ans2=ts(h-5,a-10,2) ;
	int ans3=ts(h-20,a+5,3) ;

	int final_ans=max(max(ans1,ans2),ans3) ;
	
	cout<<final_ans<<"\n" ;
	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	//y=1 ;
	cin>>y ;

	while(y--)
	{		
		solve() ;

	}

}