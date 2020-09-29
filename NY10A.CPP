#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
 
 	int x ;
 	cin>>x ;

 	string s ;
 	cin>>s ;

 	int count[8] ;
 	for(int i=0;i<8;i++){
 		count[i]=0 ;
 	}


 	for(int i=0;i<s.length()-2;i++){
 		string sub=s.substr(i,3) ;
 		if(sub=="TTT")
 			count[0]++ ;
 		else if(sub=="TTH")
 			count[1]++ ;
 		if(sub=="THT")
 			count[2]++ ;
 		if(sub=="THH")
 			count[3]++ ;
 		if(sub=="HTT")
 			count[4]++ ;
 		if(sub=="HTH")
 			count[5]++ ;
 		if(sub=="HHT")
 			count[6]++ ;
 		if(sub=="HHH")
 			count[7]++ ;

 	}

 	cout<<x<<" "<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<count[3]<<" "<<count[4]<<" "<<count[5]<<" "<<count[6]<<" "<<count[7]<<"\n" ;


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