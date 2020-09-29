#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

int aux[30001] ;

int merge(int *jumbo,int l,int m,int r){

	int i,j,k ;

	for(i=m+1;i>l;i--){
		aux[i-1]=jumbo[i-1] ;
	}

	for(j=m;j<r;j++){
		aux[r+m-j]=jumbo[j+1] ;
	}

	int ans=0 ;

	for(k=l;k<=r;k++){

		if(aux[j]<aux[i])
		{	
			jumbo[k]=aux[j--] ;
			ans=ans+(m-i+1) ;
		}
		else
		
			jumbo[k]=aux[i++] ;

	}

	return ans ;
}


int merge_sort(int *jumbo,int l,int r){

	int m=(l+r)/2 ;
	
	if(r<=l){
		return 0 ;
	}
	
	int ans1=merge_sort(jumbo,l,m) ;
	int ans2=merge_sort(jumbo,m+1,r) ;
	int ans3=merge(jumbo,l,m,r) ;

	return ans1+ans2+ans3 ;

}

void solve(){
	

	int n ;
	cin>>n ;

	vector<string> jumbled ;
	vector<string> correct ;

	map<string,int> m ;

	int jumbo[n] ;

	for(int i=1;i<=n;i++){
		string s ;
		cin>>s ;
		jumbled.push_back(s) ;
	}

	for(int i=1;i<=n;i++){
		string s ;
		cin>>s ;
		correct.push_back(s) ;
		m[s]=i ;
	}


	for(int i=0;i<n;i++){

		jumbo[i]=m[jumbled[i]] ;

	}

	/*
	for(int i=0;i<n;i++){
		cout<<jumbo[i]<<" " ;
	}
	*/

	int ans=merge_sort(jumbo,0,n-1) ;
	cout<<ans<<"\n" ;

	/*
	for(int i=0;i<n;i++){
		cout<<jumbo[i]<<" " ;
	}
	*/

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