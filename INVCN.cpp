#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

ll merge(ll *a,ll s,ll mid,ll e){

	ll temp[e-s+1] ;

	ll i=s ;
	ll j=mid+1 ;
	ll k=0 ;

	ll c=0 ;

	while(i<=mid&&j<=e){

		if(a[i]>a[j]){
			temp[k]=a[j] ;
			j++ ;
			k++ ;
			c=c+(mid-i+1) ;
		}
		else{
			temp[k]=a[i] ;
			i++ ;
			k++ ;
		}

	}

	while(i<=mid){
		temp[k]=a[i] ;
			i++ ;
			k++ ;

	}

	while(j<=e){
		temp[k]=a[j] ;
		j++ ;
		k++ ;

	}
	for(int i=s;i<=e;i++){
	a[i]=temp[i-s];
}

return c ;

}

ll mergesort(ll *a,ll s,ll e){

	if(s<e){

		ll mid=(s+e)/2 ;
		ll inv1=mergesort(a,s,mid) ;
		ll inv2=mergesort(a,mid+1,e) ;
		ll inv3=merge(a,s,mid,e) ;
		return inv1+inv2+inv3 ;
	}
	else{
		return 0 ;
	}
	
}

void solve(){

	ll n ;
	cin>>n ;
	ll a[n] ;
	for(ll i=0;i<n;i++){
		cin>>a[i] ;
	}
	
	ll c=mergesort(a,0,n-1) ;
	cout<<c<<"\n" ;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;
	//y=1 ;

	cin>>y;
	while (y--)
	{	 
		solve() ;
	
	}
}