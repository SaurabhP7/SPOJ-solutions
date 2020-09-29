#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


int acode(string s){
	int sz=s.length() ;
	int DP[sz+1] ;
	for(int i=0;i<=sz;i++){
		DP[i]=0 ;
	}

	DP[0]=DP[1]=1 ;

	for(int i = 2; i <= sz; i++)
	{
	 	if(s[i-1]!='0')
	 		DP[i] = DP[i-1];
	 	if(s[i-2]>48 && (10*(s[i-2]-48) + (s[i-1] - 48) <= 26))
			DP[i] += DP[i-2];
	
	}
	return DP[sz] ;
}

void solve(string s){
	
	int ans=acode(s) ;
	cout<<ans<<"\n" ;
	
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	string y ;
	
	cin>>y ;

	while (y.compare("0")!=0)
	{	 
		solve(y) ;
		cin>>y ;
	}
}