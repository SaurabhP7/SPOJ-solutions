#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

ll* smallestelementRight(ll *a,ll n){

	stack<ll> st ;
	
	ll* ans=new ll[n] ;
	
	for(ll next=0;next<n;next++){

		if(st.empty()){
			
			st.push(0) ;
			continue ;
		}

		while(!st.empty() && a[next]<a[st.top()])	
			{	
				ans[st.top()]=next ;
				st.pop()  ;
			}
		
		st.push(next) ;			

	}

	while(!st.empty()){
		ans[st.top()]=-1 ;
		st.pop() ;	
	}

	return ans ;

}


ll * smallestelementLeft(ll *a,ll n){

	stack<ll> st ;

	ll* ans=new ll[n] ;

	for(ll next=n-1;next>=0;next--){

		if(st.empty()){
			st.push(next) ;
			continue ;
		}

		while(!st.empty() && a[next]<a[st.top()])
		{
			ans[st.top()]=next ;
			st.pop() ;
		}			

		st.push(next) ;

	}

	while(!st.empty()){
		ans[st.top()]=-1 ;
		st.pop() ;
	}

	return ans ;

}


void solve(ll n){

	ll a[n] ;
	for(ll i=0;i<n;i++){
		cin>>a[i] ;
	}

	if(n==1){
		cout<<a[0]<<"\n" ;
		return ;
	}
	/*
	for(ll i=0;i<n;i++){
		cout<<a[i]<<" " ;
	}    
	cout<<"\n" ;
	*/
	ll *ans1=smallestelementRight(a,n) ;
    /*
    for(ll i=0;i<n;i++){
		cout<<ans1[i]<<" " ;
	}

	cout<<"\n" ;
	*/
	ll *ans2=smallestelementLeft(a,n) ;
	/*
	for(ll i=0;i<n;i++){
		cout<<ans2[i]<<" " ;
	}

	cout<<"\n" ;
	*/
	ll ans3[n] ;
	
	for(ll i=0;i<n;i++){

		if(ans1[i]==-1 && ans2[i]==-1){
			ans3[i]=a[i]*n ;
		}

		else if(ans1[i]!=-1 && ans2[i]==-1){
			ans3[i]=a[i]*(ans1[i]) ;
		}

		else if(ans1[i]==-1 && ans2[i]!=-1){

			ans3[i]=a[i]*(n-ans2[i]-1);
		}

		else{
			ans3[i]=a[i]*(abs(ans1[i]-ans2[i]-1)) ;
		}

	}
	/*
	for(ll i=0;i<n;i++){
		cout<<ans3[i]<<" " ;
	}
	cout<<"\n" ;
	*/
	ll max=-1 ;
	for(ll i=0;i<n;i++){
		if(ans3[i]>max){
			max=ans3[i] ;
		}
	}

	cout<<max<<"\n" ;

}	


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	
	ll y ;

	while(cin>>y){
		if(y==0){
			break ;
		}
		solve(y) ;

	}

}