#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
		int n,k ;

		cin>>n ;

		int a[n] ;

		for(int i=0;i<n;i++){
			cin>>a[i] ;
		}

		cin>>k ;

		vector<int> ans ;


		int curr_max=-1 ;

		for(int i=0;i<n;i++){

			curr_max=max(curr_max,a[i]) ;

			if(i>=k-1){

				ans.push_back(curr_max) ;
				if(a[i-(k-1)]==curr_max){
					int max=a[i-(k-2)] ;
					for(int j=i-(k-2);j<=i;j++)
						{
							if(a[j]>max){
								max=a[j] ;
							}

						}
					curr_max=max ;
				}
			}

		}

		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" " ;
		}			
		

	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	ll y ;

	y=1 ;
	//cin>>y ;

	while(y--){

		solve() ;

	}

}