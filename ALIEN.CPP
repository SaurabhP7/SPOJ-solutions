#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mod 1000000007 

void solve(){

	ll n,sum ;
	cin>>n>>sum ;

	ll arr[n] ;

	for(ll i=0;i<n;i++){
		cin>>arr[i] ;
	}

	ll max_length=0 ;
	ll min_sum=0 ;


	ll var_sum=0 ;

	for(ll l=0,r=0;l<n;l++){

	  
		while(r<n && var_sum+arr[r]<=sum){
			var_sum=var_sum+arr[r] ;
			r++ ;
		}

		
		if(max_length<r-l){
			max_length=r-l ;
			min_sum=var_sum ;
		}

		if(max_length==r-l && var_sum<min_sum){
			max_length=r-l ;
			min_sum=var_sum ;
		}

		if(l==r){
			r++ ;
		}
		else
		var_sum=var_sum-arr[l] ;



	}
	cout<<min_sum<<" "<<max_length<<"\n" ;


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