#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int n ;
	cin>>n ;

	double ans=0 ;

	map<string,int> m ;

	for(int i=1;i<=n;i++){

		string s ;
		cin>>s ;


		if(s.compare("1/4")==0){
			m["1/4"]++ ;
		}
		else if(s.compare("1/2")==0){
			m["1/2"]++ ;
		}
		else{
			m["3/4"]++ ;
		}
	}
	
	ans+=m["3/4"] ;

	m["1/4"]-=m["3/4"] ;

	if(m["1/2"]%2==0){
		ans+=m["1/2"]/2 ;
	}
	else{
		ans+=(m["1/2"]+1)/2 ;
		m["1/4"]=m["1/4"]-2 ;
	}

	if(m["1/4"]>0)
		ans+=(m["1/4"]/4)+1 ;

	ans=ans+1 ;
	cout<<ans;

	//cout<<m["1/4"]<<m["1/2"]<<m["3/4"] ;	

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