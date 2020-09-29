#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


void streetParade(vector<int> &v){

	int m=v.size() ;
	int n=m-1 ;
	stack<int> st ;
	vector<int> ans ;
	int i=0;

	while(i<=n-2){

		if(v[i]<v[i+1]){
			ans.push_back(v[i]) ;
			if(!st.empty()){		
				while(!st.empty()&&st.top()<v[i+1]){
					int u=st.top()  ;
					ans.push_back(u) ;
					st.pop() ;
				}
			}

			i++ ;
		}
		else{
			st.push(v[i]) ;
			i++ ;
		}
	}

	int z=i ;

	st.push(v[z]) ;

	while(!st.empty()){
		int u=st.top()  ;
		ans.push_back(u) ;
		st.pop() ;
	}

 	int f=0 ;

	for(int i=0;i<ans.size()-1;i++){
		if(ans[i]>ans[i+1]){
			f++ ;
		}
	}
	
	
	if(f==0){
		cout<<"yes"<<"\n" ;
	}
	else{
		cout<<"no"<<"\n" ;
 	}

}



void solve(int n){

	vector<int> v ;
	int count=0 ;
	while(count<n){
		int m ;
		cin>>m ;
		v.push_back(m) ;
		count++ ;
	}
	
	v.push_back(0) ;
	
	/*
	for(int i=0;i<v.size();i++)
		cout<<v[i] ;
	*/
	streetParade(v) ;

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	
	cin>>y ;
	while(y!=0){
		solve(y) ;
		cin>>y ;
	}
	
}