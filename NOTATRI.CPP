#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int binary_search(int *a,int n,int target){

int low=0 ;
int high=n-1 ;

while(low<high){

	int mid=low+(high-low)/2 ;

	if(a[mid]>target){
		high=mid ;
	}
	else{
		low=mid+1 ;
	}

}

if(a[low]<=target)
	return 0 ;

return n-low ;

}

void solve(int n){

	int a[n] ;

	for(int i=0;i<n;i++){
		cin>>a[i]  ;
	}

	sort(a,a+n) ;

	/*
	int x=binary_search(a,n,a[0]+a[1]) ;
	cout<<x<<"\n" ;
	*/
	
	int count=0 ;

	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){

			count=count+binary_search(a,n,a[i]+a[j]) ;

		}
	}

	cout<<count<<"\n" ;
	
	/*
	for(int i=0;i<n;i++){
		cout<<a[i]<<" " ;
	}
	cout<<"\n" ;
	*/
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	int y ;

	//y=1 ;
	//cin>>y ;

	while(cin>>y)
	{	
		if(y==0)
			break ;
		solve(y) ;
	}

}