#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int binary_search(int target,int arr[],int size){

	int lo=0 ;
	int hi=size-1 ;

	while(lo<=hi){

		int mid=lo+(hi-lo)/2;

		if(arr[mid]==target){
			return mid ;
		}
		else{

			if(arr[mid]<target){
				lo=mid+1 ;
			}
			else{
				hi=mid-1 ;
			}

		}
 	}

 	return -1 ; 

}


void solve(int y){

	int m=y ;
	
	int a[m] ;
	
	for(int i=0;i<m;i++){
		cin>>a[i] ;
	}		
	
	int n ;
	cin>>n ;
	
	int b[n] ;
	
	for(int i=0;i<n;i++){
		cin>>b[i] ;
	}
/*
	for(int i=0;i<m;i++){
		cout<<a[i]<<" " ;
	}
	
	cout<<"\n" ;

	for(int i=0;i<n;i++){
		cout<<b[i]<<" " ;
	}
		
	cout<<"\n" ;	
*/
	vector<int> common_number ;

	if(m<n){

		for(int i=0;i<m;i++){
			int x=binary_search(a[i],b,n) ;
			if(x!=-1)
				common_number.push_back(b[x]) ;
		}

	}
	else{

		for(int i=0;i<n;i++){
			int y=binary_search(b[i],a,m) ;
			if(y!=-1)
				common_number.push_back(a[y]) ;
		}

	}
	/*
	cout<<common_number.size()<<"\n" ;

	for(int i=0;i<common_number.size();i++){
		cout<<a[common_number[i]]<<" " ;
	}
	cout<<"\n" ;
	*/

	int i=0 ;
	int j=0 ;

	int maxsum=0 ;
	int k=0 ;
	
	while(k<common_number.size())
	{
	int sum1=0 ;
	while(a[i]!=common_number[k]){
		sum1=sum1+a[i] ;
		i++ ;
	}	
	//cout<<sum1<<"\n" ;

	int sum2=0 ;
	while(b[j]!=common_number[k]){
		sum2=sum2+b[j] ;
		j++ ;
	}

	//cout<<sum2<<"\n" ;

	maxsum=maxsum+max(sum1,sum2)+common_number[k] ;
	
	k++ ;
	i++ ;
	j++ ;
	
	//cout<<maxsum<<"\n" ;

	}

	int outer_Sum1=0;
	while(i<m){
		outer_Sum1=outer_Sum1+a[i] ;
		i++ ;
	}

	int outer_Sum2=0;
	while(j<n){
		outer_Sum2=outer_Sum2+b[j] ;
		j++ ;
	}

	maxsum+=max(outer_Sum1,outer_Sum2) ;
	
	cout<<maxsum<<"\n" ;


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
		
	while(cin>>y)
	{	 if(y==0){
			break ;
		}
		solve(y) ;
	}
}