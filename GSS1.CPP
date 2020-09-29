#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


struct data
{
	int sum,pref,suff,ans ;
};

data t[4*50000] ;

data make_data(int val){

	data res ;
	res.sum=val ;
	res.pref=res.suff=res.ans=val ;
	return res ;

}

data combine(data l ,data r){

	data res ;
	res.sum=l.sum+r.sum ;
	res.pref=max(l.pref,l.sum+r.pref) ;
	res.suff=max(r.suff,r.sum+l.suff) ;
	res.ans=max(max(l.ans,r.ans),l.suff+r.pref) ;
	return res ;

}


void build_segmentTree(int a[],int v,int tl,int tr){

	if(tl==tr){
		t[v]=make_data(a[tl]) ;
	}

	else{


		int tm=(tl+tr)/2 ;
		build_segmentTree(a,v*2,tl,tm) ;
		build_segmentTree(a,v*2+1,tm+1,tr) ;

		t[v]=combine(t[v*2],t[(v*2)+1]) ;

	}


}

data query(int v,int tl,int tr,int l,int r){


	if(tl==l && tr==r){
		return t[v] ;
	}

	int tm=(tl+tr)/2 ;

	if(r<=tm){
		return query(v*2,tl,tm,l,r) ;
	}

	if(l>tm){
		return query((v*2)+1,tm+1,tr,l,r) ;
	}

	return combine(query(v*2,tl,tm,l,tm),query((v*2)+1,tm+1,tr,tm+1,r)) ;

}


void solve(){

	
	int n ;
	cin>>n ;

	int a[n] ;

	for(int i=0;i<n;i++){
		cin>>a[i] ;
	}

	build_segmentTree(a,1,0,n-1) ;

	int q ;
	cin>>q ;

	for(int i=1;i<=q;i++){

		int l,r ;
		cin>>l>>r ;
		l-- ;
		r-- ;
		data x=query(1,0,n-1,l,r) ;
		cout<<x.ans<<"\n" ;
	}
	/*
	for(int i=1;i<=3;i++){
		cout<<t[i].sum<<" "<<t[i].pref<<" "<<t[i].suff<<" "<<t[i].ans ;
		cout<<"\n" ;
	}
	*/
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