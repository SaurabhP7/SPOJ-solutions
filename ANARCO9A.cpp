#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

string s ;
int len ;




void solve(int count){

	len=s.length() ;

	stack<char> st ;

	int k=0 ;
	while(k<len){

		char c=s[k] ;
		if(!st.empty()){

			if(s[k]=='}'&&st.top()=='{')
			{
				st.pop() ;
				k++ ;
				continue ;
			}

		}
		
			st.push(s[k]) ;
			k++ ;
	

	}

	int ans=0 ;

	while(!st.empty())
	{
		char r=st.top();	
		st.pop() ;
		char t=st.top() ;

		if(t==r){
			ans++ ;
		}
		else{
			ans=ans+2 ;
		}
	
		st.pop() ;
	}


	cout<<count<<". "<<ans<<"\n" ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif


	
	//y=1 ;
	int k=1 ;

	while(cin>>s){
		if(s[0]=='-'){
			break ;
		}
		solve(k) ;
		k++ ;
	}
}