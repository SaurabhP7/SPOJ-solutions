#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

ll t[400001] ;

void build(ll *a,int v,int tl,int tr){

	if(tl==tr){
		t[v]=a[tl] ;
	}
	else{

	int tm=(tr+tl)/2 ;
	build(a,v*2,tl,tm) ;
	build(a,(v*2)+1,tm+1,tr) ;
	t[v]=0 ;

	}

}

void update(int v,int tl,int tr, int l ,int r,int add){

	if(l>r){
		return ;
	}

	if(tl==l && tr==r){
		t[v]+=add ;
	}
	else{

		int tm=(tl+tr)/2 ;
		update(v*2,tl,tm,l,min(r,tm),add) ;
		update((v*2)+1,tm+1,tr,max(l,tm+1),r,add) ;

	}

}

ll query(int v,int tl,int tr,int l,int r){

	if(l>r){
		return 0 ;
	}

	if(tl==l && tr==r){

		return t[v] ;

	}

	int tm=(tl+tr)/2 ;

	return query(v*2,tl,tm,l,min(r,tm))+query((v*2)+1,tm+1,tr,max(l,tm+1),r) ;

}


void solve(){

	int n,c ;
	cin>>n>>c ;

	//cout<<n<<c<<"\n" ;

	ll a[n] ;

	for(int i=0;i<n;i++){
		a[i]=0 ;
	}


	build(a,1,0,n-1) ;

	for(int i=1;i<=c;i++){

		int x ;
		cin>>x ;

		if(x==0){
			int l,r,add ;
			cin>>l>>r>>add ;

			l=l-1 ;
			r=r-1 ;
			update(1,0,n-1,l,r,add) ;

		}
		else{

			int l,r ;
			cin>>l>>r ;

			l=l-1 ;
			r=r-1 ;

			ll ans=query(1,0,n-1,l,r) ;

			cout<<ans<<"\n" ;
		}

	}

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	cin>>y ;
	
	while(y--)
	{	
		solve() ;
	}

}