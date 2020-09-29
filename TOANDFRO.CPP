#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(int c){

	string s ;
	cin>>s ;

	int n=s.length() ;

	int r=n/c ;
	
	//cout<<s<<n<<" "<<r<<" "<<c<<"\n" ;

	
	vector<string> arr ;

	int count=0 ;

	for(int i=0;i<n;i=i+c){

		string x=s.substr(i,c) ;

		if(count%2==0)
			arr.push_back(x) ;
		else
			{
				reverse(x.begin(),x.end()) ;
				arr.push_back(x) ;

			}

		count++ ;
	}

	for(int i=0;i<c;i++){
		for(int j=0;j<r;j++){
			cout<<arr[j][i] ;
		}
	}

	cout<<"\n" ;
	/*
	for(int i=0;i<r;i++){

		cout<<arr[i]<<"\n" ;
	
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
	
	while(cin>>y)
	{		
		if(y==0)
			break ;
		solve(y) ;
	}

}