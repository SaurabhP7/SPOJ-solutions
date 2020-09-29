#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

vector<int> prefix_function(string s){

	int n=(int)s.length() ;

	vector<int> pi(n) ;

	for(int i=1;i<n;i++){

		int j=pi[i-1] ;
		while(j>0 && s[i]!=s[j]){
			j=pi[j-1] ;
		}

		if(s[i]==s[j])
			j++ ;
		
		pi[i]=j ;
	}

	return pi ;
	
}


void solve(ll y){

	string s ;
	cin>>s ;
	string t ;
	cin>>t ;

	ll string_size=y ;
	ll text_size=t.length() ;

	if(string_size>text_size){

		cout<<"\n" ;
		return ;
	}

	string combine=s+'#'+t ;

	//cout<<combine<<"\n" ;

	
	vector<int> pi=prefix_function(combine) ;

	ll flag=0 ;

	for(int i=0;i<pi.size();i++){
		
		if(pi[i]==string_size){
			cout<<i-2*string_size<<"\n" ;
			flag++ ;
		}

	}

	if(flag==0){
		cout<<"\n" ;
	}
	
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;
	
	while(cin>>y)
	{	 
		solve(y) ;
	}
}