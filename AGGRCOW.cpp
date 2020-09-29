#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

bool check(int *a,int n,int m,int c,int s,int e){
	int f=a[0] ;
	int temp=1 ;
	for(int k=1;k<=n-1;k++){
		if(a[k]-f>=m){
			temp++ ;
			f=a[k];
		}
	}
	if(temp<c){
		return false ;
	}
	else{
		return true ;
	}
}


int bsearch(int *a,int n,int c){




	ll s=1 ,e=1000000001 ;
	int ans=-1 ;
	while(s<=e){
		
		int mid=s+(e-s)/2 ;

		if(check(a,n,mid,c,s,e)){
			ans=mid ;
			s=mid+1 ;
		}else{
			e=mid-1;
		}

	}
	return ans ;

}

void solve(){

int n, c;
cin>>n>>c ;

int a[n] ;
for(int i=0;i<n;i++) {
	cin>>a[i] ;
}

sort(a,a+n) ;

int ans=bsearch(a,n,c) ;
cout<<ans<<"\n" ;


}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	cin>>y ;	 
	while (y--)
	{	 
		solve() ;
	}
}