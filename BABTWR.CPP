#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

struct box
{
	int l,b,h ;
};

bool compare(const box &a1,const box &a2){

	return (a1.l*a1.b)<(a2.l*a2.b) ;

}

int tallest_height(vector<box> &boxes,int n){

	int dp[6*n] ;

	for(int i=0;i<6*n;i++){
		dp[i]=boxes[i].h ;
	}

	int mx=dp[0] ;

	for(int i=0;i<6*n;i++){

		for(int j=0;j<i;j++){

			if(dp[j]+boxes[i].h>dp[i] && boxes[j].l<boxes[i].l && boxes[j].b<boxes[i].b)
				dp[i]=dp[j]+boxes[i].h ;
			
		}		

		mx=max(mx,dp[i]) ;

	}
	
	/*
	for(int i=0;i<6*n;i++){
		cout<<dp[i]<<" " ;
	}
	
	cout<<"\n" ;
	*/

	return mx ;

}

void solve(int n){

	vector<box> boxes ;

	for(int i=0;i<6*n;i=i+6){
	
		int length,base,height ;
		cin>>length>>base>>height ;

		box box1 ;
		box1.l=length ;
		box1.b=base ;
		box1.h=height ;
		boxes.push_back(box1) ;

		box box2 ;
		box2.l=length ;
		box2.b=base ;
		box2.h=height ;
		boxes.push_back(box2) ;

		box box3 ;
		box3.l=length ;
		box3.b=height ;
		box3.h=base ;
		boxes.push_back(box3) ;
		
		box box4 ;
		box4.l=height ;
		box4.b=length ;
		box4.h=base ;
		boxes.push_back(box4) ;

		box box5 ;
		box5.l=base  ;
		box5.b=height ;
		box5.h=length ;
		boxes.push_back(box5) ;

		box box6 ;
		box6.l=height  ;
		box6.b=base ;
		box6.h=length ;
		boxes.push_back(box6) ;

	}

	sort(boxes.begin(),boxes.end(),compare) ;
	
	/*
	for(int i=0;i<6*n;i++){
		cout<<boxes[i].l<<" "<<boxes[i].b<<" "<<boxes[i].h<<"\n" ;
	}
	*/

	int ans=tallest_height(boxes,n) ;
	
	cout<<ans<<"\n" ;

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