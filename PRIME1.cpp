#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

vector<bool> segmentedSieve(ll l,ll r){

	ll lim=sqrt(r) ;
	vector<bool> mark(lim+1,false) ;

	vector<ll> primes ;

	for(ll i=2;i<=lim;++i){
		if(!mark[i])
		{
			primes.emplace_back(i) ;
			for(ll j=i*i;j<=lim;j=j+i)
				mark[j]=true ;
		}

	}

	vector<bool> is_Prime(r-l+1,true) ;
	for(ll i:primes){
		for(ll j=max((i*i),((l+i-1)/i)*i);j<=r;j=j+i)
			is_Prime[j-l]=false ;

	}

	if(l==1)
		is_Prime[0]=false ;

	return is_Prime ;
}


void solve(){
int n ;
cin>>n ;
int count=0 ;
while(count<n){

	ll l,r ;
	cin>>l>>r ;
	vector<bool> ans=segmentedSieve(l,r) ;
	

	
	for(ll i=0;i<ans.size();i++){
		if(ans[i]==true)
			cout<<i+l<<"\n" ;
	}
	
	cout<<"\n" ;
	count++ ;

}
	

}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	y=1 ;

	//cin>>y ;
	while (y--)
	{	 
		solve() ;
	
	}
}