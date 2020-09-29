#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(int y){

	int i=0 ;
	int sum=1 ;
	while(sum<y){
		sum=sum+6*i ;
		i++ ;
	}

	if(sum==y){
		cout<<"Y"<<"\n" ;

	}
	else{
		cout<<"N"<<"\n" ;
	}


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif

	int y ;

	while (cin>>y)
	{	 
		if(y==-1){
			break ;
		}
		solve(y) ;
	}
}