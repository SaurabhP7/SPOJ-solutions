#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

bool check(ll next){
	


	ll flag=0 ;

	while(next>0){

		ll q=next%10 ;
		if(q==1){
			flag++ ;
			next=next/10 ;
		}

		else if(q==0)
		{	
			next=next/10 ;
		}
		else{
			return false ;
		}
	}

	if(flag==1){
		return true ;
	}
	else{
		return false ;
	}
	

}


void solve(ll y){


	unordered_map<ll,bool> umap ;

	ll ans=1 ;

	ll next=y ;

	while(!check(next))
	{
		
		ll nsum=0 ;

		while(next>0){
			ll q=next%10 ;
			nsum=nsum+pow(q,2) ;
			next=next/10 ;
		}

		if(umap.find(nsum)==umap.end())
		{
				umap.insert(make_pair(nsum,true)) ;
				next=nsum ;
				ans++ ;

		}
		else
		{
				cout<<-1 ;
				return ;
			
		}

	}

	cout<<ans ;

	
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif


	ll y ;
	
	//y=1 ;
	cin>>y ;	

	solve(y) ;
	
}