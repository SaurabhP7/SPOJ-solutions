#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(int n){

	if(n==1){
		cout<<"TERM "<<n<<" IS "<<1<<"/"<<1<<"\n" ;
		return ;
	}
	if(n==2){
		cout<<"TERM "<<n<<" IS "<<1<<"/"<<2<<"\n" ;
		return ;
	}

	int sum=0 ;
	int x=1 ;

	while(sum<n){
		sum=sum+x ;
		x++ ;
	}
	
	x=x-1 ;

	int a,b ;

	if(x%2==0)
	{
		a=x ;
		b=1 ;

	}
	else{
		a=1 ;
		b=x ;
	}

	
	if(a!=1){
	while(sum!=n){
		a-- ;
		b++ ;
		sum-- ;
	}}
	else{
		while(sum!=n){
			a++ ;
			b-- ;
			sum-- ;
		}
	}

	cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<"\n" ;

}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;
	//y=1 ;
	cin>>y ;
	int count=0 ;
	while(count<y){
		int w ;
		cin>>w ;
		solve(w) ;
		count++ ;
	}

	
}