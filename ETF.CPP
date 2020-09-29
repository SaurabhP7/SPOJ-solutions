#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){

	int n ;
	cin>>n ;

	int result=n ;

	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				n/=i ;
			}
			result-=result/i ;
		}
	}

	if(n>1){
			result-=result/n ;
		}

	cout<<result<<"\n" ;	


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
