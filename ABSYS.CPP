#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

bool check(string s){

	int n=s.length() ;

	for(int i=0;i<n;i++){
		if(s[i]=='m'){
			return true ;
		}
	}

	return false ;

}

void solve(){

	string s1,s2,s3,s4,s5 ;
	cin>>s1>>s2>>s3>>s4>>s5 ;

	
	bool a=check(s1) ;
	bool b=check(s3) ;
	bool c=check(s5) ;
	
	if(c==true){
		int ans=stoi(s1)+stoi(s3) ;
		s5=to_string(ans) ;
		cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<"\n" ;
	}
	else if(b==true)
	{
		int ans=stoi(s5)-stoi(s1) ;
		s3=to_string(ans) ;
		cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<"\n" ;
	}
	else{

		int ans=stoi(s5)-stoi(s3) ;
		s1=to_string(ans) ;
		cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<"\n" ;
	}
		
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	ll y ;

	//y=1 ;
	cin>>y ;
	
	while(y--)
	{		
	
		solve() ;

	}

}