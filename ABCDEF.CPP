#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int express1(int a,int b,int c){

	return ((a*b)+c) ;

}

int express2(int d,int e,int f){

	return (d*(e+f)) ; 
}

int binary_search(vector<int> &v2,int n, int target){

	int lo=0 ;
	int hi=n-1 ;

	while(lo<=hi){
	
		int mid=lo+(hi-lo)/2 ;

		if(v2[mid]==target){
			return mid ;
		}
		else{

			if(v2[mid]>target){
				hi=mid-1 ;
			}
			else{
				lo=mid+1 ;
			}

		}
	}

	return -1 ;

}

void solve(){

	int n;
	cin>>n ;

	int a[n] ;

	for(int i=0;i<n;i++){
		cin>>a[i] ;
	}

	vector<int> v1 ;
	vector<int> v2 ;

	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			for(int k=0;k<=n-1;k++){
				
				int ex1=express1(a[i],a[j],a[k]) ;
				v1.push_back(ex1) ;

			}
		}
	}

	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			for(int k=0;k<=n-1;k++){

				if(a[i]==0){
					continue ;
				}
				else{
					int ex2=express2(a[i],a[j],a[k]) ;
					v2.push_back(ex2) ;
				}
			}
		}
	}

	sort(v1.begin(),v1.end()) ;
	sort(v2.begin(),v2.end()) ;

	int ans=0 ;

	for(int i=0;i<v1.size();i++){

		int idx=binary_search(v2,v2.size(),v1[i]) ;
			
			if(idx!=-1){
			
				ans++ ;

				int q=idx-1 ;
				while(q>=0 && v2[idx]==v2[q]){
					ans++ ;
					q-- ;
				}		

				int p=idx+1 ;

				while(p<=v2.size()-1 && v2[idx]==v2[p]){
					ans++ ;
					p++ ;
				}
			
			}
	}

	cout<<ans ;
	
	cout<<"\n" ;
	
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" " ;
	}

	cout<<"\n" ;

	for(int i=0;i<v2.size();i++){
		cout<<v2[i]<<" " ;

	}
	


}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;

	y=1 ;
	//cin>>y ;

	while(y--){

		solve() ;

	}

}