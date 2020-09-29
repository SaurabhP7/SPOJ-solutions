#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> lnum ;
const int base=1000*1000*1000 ;


lnum input_string(string s){

	lnum a ;
	for(int i=(int)s.length();i>0;i-=9){
		if(i<9){
			a.push_back(atoi(s.substr(0,i).c_str())) ; 
		}
		else{
			a.push_back(atoi(s.substr(i-9,9).c_str())) ;
		}
	}
	return a ;
}

void print_number(lnum a){

	printf("%d",a.empty()?0:a.back()) ;

	for(int i=(int)a.size()-2;i>=0;i--){
		printf("%09d",a[i]) ;
	}
	cout<<"\n" ;
}

lnum substract(lnum a,lnum b){

	int carry = 0;
	for (size_t i=0; i<b.size() || carry; ++i) {
	    a[i] -= carry + (i < b.size() ? b[i] : 0);
	    carry = a[i] < 0;
	    if (carry)  a[i] += base;
	}
	while (a.size() > 1 && a.back() == 0)
	    a.pop_back();

	return a ;

}

lnum multiply(lnum a,int b){

	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
	    if (i == a.size())
	        a.push_back (0);
	    long long cur = carry + a[i] * 1ll * b;
	    a[i] = int (cur % base);
	    carry = int (cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
	    a.pop_back();

	return a ;	
}

void solve(string s){

	if(s.compare("1")==0){
		cout<<1<<"\n" ;
		return ;
	}

	lnum a1=input_string(s) ;

	string s2 ;

	s2="1" ;
	lnum b1=input_string(s2) ;

	lnum a2=substract(a1,b1) ;
	lnum a3=multiply(a2,2) ;

	print_number(a3) ;

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
	
	string y ;


	while(cin>>y)
	{		
		solve(y) ;

	}

}